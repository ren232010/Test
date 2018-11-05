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
	//创建地面
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
	if (!Land)//如果加载数据失败，则直接返回，不走下面的逻辑
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

	//获取游戏的Gamemode
	FbGM = Cast<AFBGameMode>(GetWorld()->GetAuthGameMode());
}

void AFBLandActor::UpdateLandPartOffset(float Delta)
{
	if (!FbGM || !LandTwo || !LandOne || !bRun)//如果你的gm没有获取成功，就不要走下面的逻辑了
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
	//逐帧进行运转操作
	UpdateLandPartOffset(DeltaTime);
}

void AFBLandActor::ChangeGameStateCB(int32 State)
{
	bRun = false;
}

