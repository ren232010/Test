// Fill out your copyright notice in the Description page of Project Settings.

#include "FBirdPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/BodyInstance.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "FBGameMode.h"
#include "Engine/World.h"


// Sets default values
AFBirdPawn::AFBirdPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//构建一个角色的空间根组件
	//函数说明：这是一个组件构建函数，可以将组件构建完成后添加到角色身上
	USceneComponent* MainRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootCom"));//这个函数只能构造函数中调用
	SetRootComponent(MainRoot);//将创建完成的空间组件设置成为根组件

	//第一件事情，将相机驾到人身上
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	//附着到根组件上（设置层级关系 相机成了root的子级）
	MainCamera->SetupAttachment(MainRoot);//如果不装在根组件上，相机将不跟随玩家
	//调整相机的透视模式
	MainCamera->ProjectionMode = ECameraProjectionMode::Orthographic;
	//旋转相机，可以正视鸟
	MainCamera->SetRelativeRotation(FRotator(0, -90, 0));
	//调整镜头拍摄宽度
	MainCamera->OrthoWidth = 1000;

	/**************添加小鸟动画渲染组件*******************/
	BirdAnim = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("BirdAnim"));//创建渲染组件
	BirdAnim->SetupAttachment(MainRoot);
}

// Called when the game starts or when spawned
void AFBirdPawn::BeginPlay()
{
	Super::BeginPlay();
	Init();//调用初始化函数，用来初始化资产
}

void AFBirdPawn::Init()
{
	//动态加载，将资产进行内容导入
	UPaperFlipbook* Book = LoadObject<UPaperFlipbook>(nullptr, TEXT("PaperFlipbook'/Game/FlappyBird/Animations/Bird_Yellow.Bird_Yellow'"));
	if (BirdAnim && Book)//必要的安全检查
	{
		BirdAnim->SetFlipbook(Book);
		
		//锁轴
		FBodyInstance* Body = BirdAnim->GetBodyInstance();//获取组件的碰撞刚体对象
		if (Body)
		{
			Body->bLockXTranslation = true;//位移轴
			Body->bLockYTranslation = true;//位移轴

			Body->bLockXRotation = true;
			Body->bLockZRotation = true;
			//接受物理碰撞通知 如果不开启，则无法接收碰撞事件
			Body->SetInstanceNotifyRBCollision(true);

			Body->CreateDOFLock();//注意，如果没有这句话，锁定失败，无法进行锁定
		}
		//让小鸟的渲染组件去响应hit事件
		BirdAnim->OnComponentHit.AddDynamic(this, &AFBirdPawn::OnComponentHitEvent);
	}
	FlySound = LoadObject<USoundBase>(nullptr, TEXT("SoundWave'/Game/FlappyBird/Sounds/fly.fly'"));
	//ChangeState(EBirdState::EBS_Fly);
}

void AFBirdPawn::DoJump()
{
	//如果小鸟的状态不在飞行状态，则不要处理逻辑
	if (State != EBirdState::EBS_Fly)
	{
		return;
	}
	//先去消解上一次的发力速度
	BirdAnim->SetPhysicsLinearVelocity(FVector::ZeroVector);
	//为小鸟添加一个脉冲力，让它飞起来
	BirdAnim->AddImpulse(FVector(0, 0, 2000));
	if (FlySound)
	{
		UGameplayStatics::PlaySound2D(this, FlySound);
	}

}

void AFBirdPawn::OnComponentHitEvent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (State != EBirdState::EBS_Fly)
	{
		return;
	}
	//UE_LOG(LogTemp, Log, TEXT("fffffffffffffddddddddddddsssssssssssss"));
	AFBGameMode* gm = Cast<AFBGameMode>(GetWorld()->GetAuthGameMode());
	if (gm)
	{
		gm->ChangeState(EFBGameState::FBGS_GameOver);
	}
	ChangeState(EBirdState::EBS_Dead);
}

// Called every frame
void AFBirdPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateFace();
}

// Called to bind functionality to input
void AFBirdPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("DoJump"), IE_Pressed, this, &AFBirdPawn::DoJump);//绑定按键事件通知到Dojump函数
}

void AFBirdPawn::ChangeState(EBirdState::Type State)//用来操控鸟的状态切换
{
	//使用函数的目的：状态和状态之间进行切换时，经常会有额外的逻辑操作，使用函数可以统一调用逻辑入口
	switch (State)
	{
	case EBirdState::EBS_Idle:
		BirdAnim->SetRelativeLocation(FVector::ZeroVector);
		BirdAnim->SetRelativeRotation(FRotator::ZeroRotator);
		break;
	case EBirdState::EBS_Fly:
		BirdAnim->SetSimulatePhysics(true);//开启小鸟的物理模拟，让他掉下去
		break;
	case EBirdState::EBS_Dead:
		BirdAnim->SetSimulatePhysics(false);
		break;
	default:
		break;
	}
	this->State = State;
}

void AFBirdPawn::UpdateFace()//刷脸，调整脸的角度
{
	if (State != EBirdState::EBS_Fly || !BirdAnim)
	{
		return;
	}
	//获取当前组件的线性位移速度
	FVector Velocity = BirdAnim->GetPhysicsLinearVelocity();
	//通过位移Z轴值当作脸的朝向参考
	BirdAnim->SetRelativeRotation(FRotator(Velocity.Z * 0.1f, 0, 0));

}

