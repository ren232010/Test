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
	//����ͼ�����Ľ�ɫ����Ϊ����Ĭ��������ɫ
	DefaultPawnClass = AirClass.Class;
	//��C++�е��ʲ�������Ϊ��������Ĭ�Ͽ�����
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
	//������ͼ����
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
