// Fill out your copyright notice in the Description page of Project Settings.

#include "CBossActor.h"
#include "Components/SceneComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"
#include "SpaceEmitterComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSprite.h"
#include "CGameMode.h"
#include "Engine/World.h"
#include "FileHelper.h"
#include "JsonObject.h"
#include "JsonReader.h"
#include "JsonSerializer.h"

// Sets default values
ACBossActor::ACBossActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	SpriteRender = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteRender"));
	SpriteRender->SetupAttachment(RootComp);

	EmitterComp = CreateDefaultSubobject<USpaceEmitterComponent>(TEXT("Emitter"));
	EmitterComp->SetupAttachment(SpriteRender);

	MaxHP = 50;
	CurrentHP = MaxHP;

	CurrentBL = 0;
}

// Called when the game starts or when spawned
void ACBossActor::BeginPlay()
{
	Super::BeginPlay();
	UPaperSprite* Sprite = LoadObject<UPaperSprite>(NULL, TEXT("PaperSprite'/Game/FlyGame/Textures/Boss/img_plane_enemy_Sprite_6.img_plane_enemy_Sprite_6'"));
	SpriteRender->SetSprite(Sprite);
	
	//EmitterComp->DoFire(EBGType::EBG_Yuan, 10, 2);

	ACGameMode* Gm = Cast<ACGameMode>(GetWorld()->GetAuthGameMode());
	if (Gm)
	{
		Gm->SetBoss(this);
	}
	//加载数据
	//LoadBossLevel();
	//使用数据
	EmitterComp->DoFire(EBGType::EBG_Yuan, 20,0.8f);
}

void ACBossActor::LoadBossLevel()
{
	//加载Json文件
	FString Path = FPaths::ProjectSavedDir() / "1.json";

	if (!FPaths::FileExists(Path))
	{
		return;
	}
	FString JData;
	FFileHelper::LoadFileToString(JData, *Path);

	TArray<TSharedPtr<FJsonValue>> Array;
	TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(JData);
	
	if (FJsonSerializer::Deserialize(Reader, Array))
	{
		for (int32 i=0; i<Array.Num(); i++)
		{
			TSharedPtr<FBossLevel> BL(new FBossLevel());

			BL->Type = (EBGType::Type)((int32)Array[i]->AsObject()->GetNumberField(TEXT("type")));
			BL->FireTime = Array[i]->AsObject()->GetNumberField(TEXT("fireTime"));
			BL->FireInterval = Array[i]->AsObject()->GetNumberField(TEXT("fireInterval"));

			BossLevel.Add(BL);
		}
	}
}

// Called every frame
void ACBossActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

