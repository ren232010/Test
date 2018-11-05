// Fill out your copyright notice in the Description page of Project Settings.

#include "CAirPlanePawn.h"
#include "Camera/CameraComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "CBulletActor.h"
#include "CGameMode.h"
#include "CBulletPool.h"
#include "EmitterComponent.h"
#include "SpaceEmitterComponent.h"


// Sets default values
ACAirPlanePawn::ACAirPlanePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	AirPlane = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("AirRender"));
	AirPlane->SetupAttachment(RootComp);

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(RootComp);
	MainCamera->SetRelativeRotation(FRotator(0, -90, 0));
	MainCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	
	EmitterComp = CreateDefaultSubobject<UEmitterComponent>(TEXT("EmitterComp"));

	SpaceEmitterComp = CreateDefaultSubobject<USpaceEmitterComponent>(TEXT("SpaceEmitterComp"));
	SpaceEmitterComp->SetupAttachment(AirPlane);

	MoveSpeed = 5;

	MaxHP = 15;
	CurrentHP = MaxHP;
}

// Called when the game starts or when spawned
void ACAirPlanePawn::BeginPlay()
{
	Super::BeginPlay();
	
	//获取一下屏幕的边缘坐标用于约束小鸟不要飞出去
	m_Pc = GetWorld()->GetFirstPlayerController();
	//保证游戏启动的时候，鸟不会向着0点奔袭
	PickupPos = AirPlane->GetComponentLocation();

}

void ACAirPlanePawn::MoveUp(float Value)//此函数将会逐帧调用
{
	if (Value == 0)//当我的操控器没有按下的时候，不要处理逻辑
	{
		return;
	}
	AirPlane->AddRelativeLocation(FVector(0, 0, MoveSpeed * Value));
	ClampAirPlane();
}

void ACAirPlanePawn::MoveRight(float Value)
{
	if (Value == 0)
	{
		return;
	}
	AirPlane->AddRelativeLocation(FVector(MoveSpeed * Value, 0, 0));
	ClampAirPlane();
}

void ACAirPlanePawn::MousePickupPos()
{
	FVector PorjectDir;
	m_Pc->DeprojectMousePositionToWorld(PickupPos, PorjectDir);//将鼠标右键点击的坐标进行转头到空间坐标，并进行成员变量存储
}

void ACAirPlanePawn::Fire()
{
	if (!AirPlane || !SpaceEmitterComp)
	{
		return;
	}
	SpaceEmitterComp->DoFire(EBGType::EBG_Normal, 30, 0.1);
}

void ACAirPlanePawn::ClampAirPlane()
{
	if (m_Pc && LeftTop.X == RightBottom.X)
	{
		FVector Dir;
		//转左上角的
		m_Pc->DeprojectScreenPositionToWorld(0, 0, LeftTop, Dir);

		int32 X = 0;
		int32 Y = 0;
		m_Pc->GetViewportSize(X, Y);
		//取右下角坐标
		m_Pc->DeprojectScreenPositionToWorld(X, Y, RightBottom, Dir);
	}

	float X = FMath::Clamp<float>(AirPlane->GetComponentLocation().X, LeftTop.X, RightBottom.X);//X min max
	float Z = FMath::Clamp<float>(AirPlane->GetComponentLocation().Z, RightBottom.Z, LeftTop.Z);
	
	AirPlane->SetWorldLocation(FVector(X, AirPlane->GetComponentLocation().Y, Z));
	
}

void ACAirPlanePawn::MoveToPickupPos(float Delta)
{
	if (!AirPlane)
	{
		return;
	}
	if (AirPlane->GetComponentLocation().Equals(PickupPos, 0.5f))//如果鸟和目标位置的距离小于0.5，我们就不需要再移动了
	{
		return;
	}
	//先寻找当前鸟和目标移动点之间的一个向量
	FVector MoveInterval = PickupPos - AirPlane->GetComponentLocation();
	//将向量标量化
	MoveInterval.Normalize(1);
	//将标量化后的向量当作单位偏移量，使用delta和speed进行移动
	AirPlane->AddWorldOffset(MoveInterval * MoveSpeed * Delta);
}

void ACAirPlanePawn::FollowTargetToMove(float Delta)
{
	FVector PorjectDir;
	if (m_Pc)
	{
		m_Pc->DeprojectMousePositionToWorld(PickupPos, PorjectDir);//将鼠标右键点击的坐标进行转头到空间坐标，并进行成员变量存储
	}
	if (!AirPlane)
	{
		return;
	}
	if (AirPlane->GetComponentLocation().Equals(PickupPos, 0.5f))//如果鸟和目标位置的距离小于0.5，我们就不需要再移动了
	{
		return;
	}
	//插值进行位移
	AirPlane->SetWorldLocation(FMath::Lerp<FVector>(AirPlane->GetComponentLocation(), PickupPos, 0.1f));
}

void ACAirPlanePawn::OnTouchByFingerPressed(ETouchIndex::Type Type, FVector Pos)
{
	//UE_LOG(LogTemp, Log, TEXT("Touch"));
}

void ACAirPlanePawn::OnTouchByFingerRepeat(ETouchIndex::Type Type, FVector Pos)
{
	UE_LOG(LogTemp, Log, TEXT("Touch"));
}

// Called every frame
void ACAirPlanePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//MoveToPickupPos(DeltaTime);
	//FollowTargetToMove(DeltaTime);
}

// Called to bind functionality to input
void ACAirPlanePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveUp"), this, &ACAirPlanePawn::MoveUp);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACAirPlanePawn::MoveRight);

	PlayerInputComponent->BindAction(TEXT("MousePickupPos"), IE_Pressed, this, &ACAirPlanePawn::MousePickupPos);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ACAirPlanePawn::Fire);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ACAirPlanePawn::OnTouchByFingerPressed);
	PlayerInputComponent->BindTouch(IE_Repeat, this, &ACAirPlanePawn::OnTouchByFingerRepeat);

}

class UPaperFlipbookComponent* ACAirPlanePawn::GetPlaneRenderComponent()
{
	return AirPlane;
}

