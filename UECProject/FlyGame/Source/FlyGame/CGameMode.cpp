// Fill out your copyright notice in the Description page of Project Settings.

#include "CGameMode.h"
#include "ConstructorHelpers.h"
#include "CAirPlanePawn.h"
#include "CPlayerController.h"
#include "CBgActor.h"
#include "CHUD.h"
#include "CBulletPool.h"
#include "Engine/World.h"




ACGameMode::ACGameMode()
{
	ConstructorHelpers::FClassFinder<ACAirPlanePawn> AirClass(TEXT("Blueprint'/Game/FlyGame/Blueprints/BP_AirPlane.BP_AirPlane_C'"));
	//将蓝图生产的角色设置为引擎默认启动角色
	DefaultPawnClass = AirClass.Class;
	//将C++中的资产类设置为引擎启动默认控制器
	PlayerControllerClass = ACPlayerController::StaticClass();
	HUDClass = ACHUD::StaticClass();
}



void ACGameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACGameMode::SetBgActor(ACBgActor* Bg)
{
	BgActor = Bg;
}

void ACGameMode::SetBgSpeed(float Speed)
{
	if (BgActor)
	{
		BgActor->SetBgSpeed(Speed);
	}
}

void ACGameMode::ChangeGameLevel(int32 Level)
{
	//更换地图背景
	UTexture* BgTexture = LoadObject<UTexture>(NULL, *FString::Printf(TEXT("Texture2D'/Game/FlyGame/Textures/BG/img_bg_level_%d.img_bg_level_%d'"), Level, Level));
	if (BgTexture)
	{
		BgActor->SetBgTexture(BgTexture);
	}
	CurrentLevel = Level;
}

ACBulletPool* ACGameMode::GetBulletPool()
{
	if (!Pool)
	{
		Pool = GetWorld()->SpawnActor<ACBulletPool>();
	}
	return Pool;
}

void ACGameMode::SetBoss(ACBossActor* Boss)
{
	this->Boss = Boss;
}

ACBossActor* ACGameMode::GetBoss()
{
	return Boss;
}
