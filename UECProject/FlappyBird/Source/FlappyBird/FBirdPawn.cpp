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
	//����һ����ɫ�Ŀռ�����
	//����˵��������һ������������������Խ����������ɺ���ӵ���ɫ����
	USceneComponent* MainRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootCom"));//�������ֻ�ܹ��캯���е���
	SetRootComponent(MainRoot);//��������ɵĿռ�������ó�Ϊ�����

	//��һ�����飬������ݵ�������
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	//���ŵ�������ϣ����ò㼶��ϵ �������root���Ӽ���
	MainCamera->SetupAttachment(MainRoot);//�����װ�ڸ�����ϣ���������������
	//���������͸��ģʽ
	MainCamera->ProjectionMode = ECameraProjectionMode::Orthographic;
	//��ת���������������
	MainCamera->SetRelativeRotation(FRotator(0, -90, 0));
	//������ͷ������
	MainCamera->OrthoWidth = 1000;

	/**************���С�񶯻���Ⱦ���*******************/
	BirdAnim = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("BirdAnim"));//������Ⱦ���
	BirdAnim->SetupAttachment(MainRoot);
}

// Called when the game starts or when spawned
void AFBirdPawn::BeginPlay()
{
	Super::BeginPlay();
	Init();//���ó�ʼ��������������ʼ���ʲ�
}

void AFBirdPawn::Init()
{
	//��̬���أ����ʲ��������ݵ���
	UPaperFlipbook* Book = LoadObject<UPaperFlipbook>(nullptr, TEXT("PaperFlipbook'/Game/FlappyBird/Animations/Bird_Yellow.Bird_Yellow'"));
	if (BirdAnim && Book)//��Ҫ�İ�ȫ���
	{
		BirdAnim->SetFlipbook(Book);
		
		//����
		FBodyInstance* Body = BirdAnim->GetBodyInstance();//��ȡ�������ײ�������
		if (Body)
		{
			Body->bLockXTranslation = true;//λ����
			Body->bLockYTranslation = true;//λ����

			Body->bLockXRotation = true;
			Body->bLockZRotation = true;
			//����������ײ֪ͨ ��������������޷�������ײ�¼�
			Body->SetInstanceNotifyRBCollision(true);

			Body->CreateDOFLock();//ע�⣬���û����仰������ʧ�ܣ��޷���������
		}
		//��С�����Ⱦ���ȥ��Ӧhit�¼�
		BirdAnim->OnComponentHit.AddDynamic(this, &AFBirdPawn::OnComponentHitEvent);
	}
	FlySound = LoadObject<USoundBase>(nullptr, TEXT("SoundWave'/Game/FlappyBird/Sounds/fly.fly'"));
	//ChangeState(EBirdState::EBS_Fly);
}

void AFBirdPawn::DoJump()
{
	//���С���״̬���ڷ���״̬����Ҫ�����߼�
	if (State != EBirdState::EBS_Fly)
	{
		return;
	}
	//��ȥ������һ�εķ����ٶ�
	BirdAnim->SetPhysicsLinearVelocity(FVector::ZeroVector);
	//ΪС�����һ��������������������
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
	PlayerInputComponent->BindAction(TEXT("DoJump"), IE_Pressed, this, &AFBirdPawn::DoJump);//�󶨰����¼�֪ͨ��Dojump����
}

void AFBirdPawn::ChangeState(EBirdState::Type State)//�����ٿ����״̬�л�
{
	//ʹ�ú�����Ŀ�ģ�״̬��״̬֮������л�ʱ���������ж�����߼�������ʹ�ú�������ͳһ�����߼����
	switch (State)
	{
	case EBirdState::EBS_Idle:
		BirdAnim->SetRelativeLocation(FVector::ZeroVector);
		BirdAnim->SetRelativeRotation(FRotator::ZeroRotator);
		break;
	case EBirdState::EBS_Fly:
		BirdAnim->SetSimulatePhysics(true);//����С�������ģ�⣬��������ȥ
		break;
	case EBirdState::EBS_Dead:
		BirdAnim->SetSimulatePhysics(false);
		break;
	default:
		break;
	}
	this->State = State;
}

void AFBirdPawn::UpdateFace()//ˢ�����������ĽǶ�
{
	if (State != EBirdState::EBS_Fly || !BirdAnim)
	{
		return;
	}
	//��ȡ��ǰ���������λ���ٶ�
	FVector Velocity = BirdAnim->GetPhysicsLinearVelocity();
	//ͨ��λ��Z��ֵ�������ĳ���ο�
	BirdAnim->SetRelativeRotation(FRotator(Velocity.Z * 0.1f, 0, 0));

}

