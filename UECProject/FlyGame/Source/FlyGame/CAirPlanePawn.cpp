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
	
	//��ȡһ����Ļ�ı�Ե��������Լ��С��Ҫ�ɳ�ȥ
	m_Pc = GetWorld()->GetFirstPlayerController();
	//��֤��Ϸ������ʱ���񲻻�����0�㱼Ϯ
	PickupPos = AirPlane->GetComponentLocation();

}

void ACAirPlanePawn::MoveUp(float Value)//�˺���������֡����
{
	if (Value == 0)//���ҵĲٿ���û�а��µ�ʱ�򣬲�Ҫ�����߼�
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
	m_Pc->DeprojectMousePositionToWorld(PickupPos, PorjectDir);//������Ҽ�������������תͷ���ռ����꣬�����г�Ա�����洢
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
		//ת���Ͻǵ�
		m_Pc->DeprojectScreenPositionToWorld(0, 0, LeftTop, Dir);

		int32 X = 0;
		int32 Y = 0;
		m_Pc->GetViewportSize(X, Y);
		//ȡ���½�����
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
	if (AirPlane->GetComponentLocation().Equals(PickupPos, 0.5f))//������Ŀ��λ�õľ���С��0.5�����ǾͲ���Ҫ���ƶ���
	{
		return;
	}
	//��Ѱ�ҵ�ǰ���Ŀ���ƶ���֮���һ������
	FVector MoveInterval = PickupPos - AirPlane->GetComponentLocation();
	//������������
	MoveInterval.Normalize(1);
	//���������������������λƫ������ʹ��delta��speed�����ƶ�
	AirPlane->AddWorldOffset(MoveInterval * MoveSpeed * Delta);
}

void ACAirPlanePawn::FollowTargetToMove(float Delta)
{
	FVector PorjectDir;
	if (m_Pc)
	{
		m_Pc->DeprojectMousePositionToWorld(PickupPos, PorjectDir);//������Ҽ�������������תͷ���ռ����꣬�����г�Ա�����洢
	}
	if (!AirPlane)
	{
		return;
	}
	if (AirPlane->GetComponentLocation().Equals(PickupPos, 0.5f))//������Ŀ��λ�õľ���С��0.5�����ǾͲ���Ҫ���ƶ���
	{
		return;
	}
	//��ֵ����λ��
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

