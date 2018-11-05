// Fill out your copyright notice in the Description page of Project Settings.

#include "FBPipeActor.h"
#include "Components/SceneComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSprite.h"
#include "FBGameMode.h"
#include "Engine/World.h"
#include "FBGameState.h"


// Sets default values
AFBPipeActor::AFBPipeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootComp);

	
	for (int32 i=0; i<3; i++)
	{
		FPipeGroup pg;
		for (int32 j=0; j<2; j++)
		{
			UPaperSpriteComponent* Pipe = CreateDefaultSubobject<UPaperSpriteComponent>(*FString::Printf(TEXT("Sprite_%d_%d"), i, j));
			Pipe->SetupAttachment(RootComp);
			if (j == 0)
			{
				pg.Up = Pipe;
			}
			else
			{
				pg.Down = Pipe;
			}
		}
		PipeGroup.Add(pg);//因为数据会被拷贝
	}

	bRun = true;
}

// Called when the game starts or when spawned
void AFBPipeActor::BeginPlay()
{
	Super::BeginPlay();
	Init();

	//测试加分
	AFBGameState* Gs = Cast<AFBGameState>(GetWorld()->GetGameState());
	if (Gs)
	{
		Gs->AddScore();
	}
}


void AFBPipeActor::Init()
{
	UPaperSprite* UpSprite = LoadObject<UPaperSprite>(NULL, TEXT("PaperSprite'/Game/FlappyBird/Textures/BG/pipe_down_Sprite.pipe_down_Sprite'"));
	UPaperSprite* DownSprite = LoadObject<UPaperSprite>(NULL, TEXT("PaperSprite'/Game/FlappyBird/Textures/BG/pipe_up_Sprite.pipe_up_Sprite'"));

	for (int32 i=0; i<PipeGroup.Num(); i++)
	{
		if (PipeGroup[i].Up)
		{
			PipeGroup[i].Up->SetSprite(UpSprite);
		}
		if (PipeGroup[i].Down)
		{
			PipeGroup[i].Down->SetSprite(DownSprite);
		}

		PipeGroup[i].OffsetX = i * 170 + 200;
		PipeGroup[i].RandomPipePos();
	}

	pGm = Cast<AFBGameMode>(GetWorld()->GetAuthGameMode());
}

void AFBPipeActor::UpdatePipeGroupPos(float Delta)
{
	if (!pGm || !bRun)//终止进行滚动
	{
		return;
	}
	for (int32 i=0; i<PipeGroup.Num(); i++)
	{
		PipeGroup[i].OffsetX -= pGm->GetSpeed() * Delta;
		PipeGroup[i].UpdatePipePos();
	}
}

// Called every frame
void AFBPipeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdatePipeGroupPos(DeltaTime);
}

void AFBPipeActor::ChangeGameStateCB(int32 State)
{
	if (State == EFBGameState::FBGS_ResetGame)//GM通知我，要重置一下管子的位置啊
	{
		//重置管子的位置
		for (int32 i=0; i<PipeGroup.Num(); i++)
		{
			PipeGroup[i].OffsetX = 0;
			PipeGroup[i].OffsetX = i * 170 + 200;
			PipeGroup[i].RandomPipePos();
		}
	}
	else if (State == EFBGameState::FBGS_GameOver)//GM通知我，游戏结束了啊
	{
		bRun = false;
	}
}

void FPipeGroup::RandomPipePos()
{
	if (!Up || !Down)
	{
		return;
	}
	Up->SetRelativeLocation(FVector(OffsetX, -3, 160 + FMath::FRandRange(-100, 200)));
	Down->SetRelativeLocation(FVector(OffsetX, -3, Up->GetComponentLocation().Z - 440));
}

void FPipeGroup::UpdatePipePos()
{
	if (!Up || !Down)
	{
		return;
	}
	Up->SetRelativeLocation(FVector(OffsetX, 0, Up->GetComponentLocation().Z));
	Down->SetRelativeLocation(FVector(OffsetX, 0, Down->GetComponentLocation().Z));
}
