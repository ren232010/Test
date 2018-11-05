// Fill out your copyright notice in the Description page of Project Settings.

#include "FBLandActor.h"
#include "Components/SceneComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSprite.h"
#include "Engine/World.h"
#include "FBGameMode.h"
#include "PhysicsEngine/BodyInstance.h"


// Sets default values
AFBLandActor::AFBLandActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* RootCom = CreateDefaultSubobject<USceneComponent>(TEXT("RootCom"));
	SetRootComponent(RootCom);
	//��������
	LandOne = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("LandRenderOne"));
	LandTwo = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("LandRenderTwo"));

	LandTwo->SetupAttachment(RootCom);
	LandOne->SetupAttachment(RootCom);

	bRun = true;
}

// Called when the game starts or when spawned
void AFBLandActor::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void AFBLandActor::Init()
{
	UPaperSprite* Land = LoadObject<UPaperSprite>(NULL, TEXT("PaperSprite'/Game/FlappyBird/Textures/Land/land_Sprite.land_Sprite'"));
	if (!Land)//�����������ʧ�ܣ���ֱ�ӷ��أ�����������߼�
	{
		return;
	}
	if (LandOne)
	{
		LandOne->SetSprite(Land);
		LandOne->SetRelativeLocation(FVector(0, 0, -200));
		

	}
	if (LandTwo)
	{
		LandTwo->SetSprite(Land);
		LandTwo->SetRelativeLocation(FVector(336, 0, -200));
		
	}

	//��ȡ��Ϸ��Gamemode
	FbGM = Cast<AFBGameMode>(GetWorld()->GetAuthGameMode());
}

void AFBLandActor::UpdateLandPartOffset(float Delta)
{
	if (!FbGM || !LandTwo || !LandOne || !bRun)//������gmû�л�ȡ�ɹ����Ͳ�Ҫ��������߼���
	{
		return;
	}
	LandOne->AddRelativeLocation(FVector(FbGM->GetSpeed() * Delta * -1, 0, 0));
	LandTwo->AddRelativeLocation(FVector(FbGM->GetSpeed() * Delta * -1, 0, 0));

	if (LandOne->GetComponentLocation().X < -336)
	{
		LandOne->SetRelativeLocation(FVector(LandTwo->GetComponentLocation().X + 336, 0, -200));
	}
	if (LandTwo->GetComponentLocation().X < -336)
	{
		LandTwo->SetRelativeLocation(FVector(LandOne->GetComponentLocation().X + 336, 0, -200));
	}
}

// Called every frame
void AFBLandActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//��֡������ת����
	UpdateLandPartOffset(DeltaTime);
}

void AFBLandActor::ChangeGameStateCB(int32 State)
{
	bRun = false;
}

