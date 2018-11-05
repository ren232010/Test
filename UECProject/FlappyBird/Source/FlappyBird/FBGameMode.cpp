// Fill out your copyright notice in the Description page of Project Settings.

#include "FBGameMode.h"
#include "FBirdPawn.h"
#include "FBPlayerController.h"
#include "FBGameState.h"
#include "FBgActor.h"
#include "Engine/World.h"
#include "FBLandActor.h"
#include "FBPipeActor.h"
#include "FBHUD.h"




AFBGameMode::AFBGameMode()
{
	//设置游戏启动默认角色
	DefaultPawnClass = AFBirdPawn::StaticClass();//StaticClass 快速获取一个类的类模版资产
	//设置引擎启动的默认PlayerController
	PlayerControllerClass = AFBPlayerController::StaticClass();
	//设置引擎框架中的默认游戏状态
	GameStateClass = AFBGameState::StaticClass();
	//设置游戏默认的HUD
	HUDClass = AFBHUD::StaticClass();

	Speed = 150;
}

void AFBGameMode::BeginPlay()
{
	InitFB();
}

void AFBGameMode::InitFB()
{
	//配置背景
	auto BgActor = GetWorld()->SpawnActor<AFBgActor>(FVector(0, -100, 0), FRotator::ZeroRotator);
	//配置路面
	auto LandActor = GetWorld()->SpawnActor<AFBLandActor>();
	//创建管道
	auto PipeActor = GetWorld()->SpawnActor<AFBPipeActor>();
	
	//绑定多播，将需要获得游戏状态通知的对象进行绑定
	NotifyGS.AddUObject(LandActor, &AFBLandActor::ChangeGameStateCB);
	NotifyGS.AddUObject(PipeActor, &AFBPipeActor::ChangeGameStateCB);

}

void AFBGameMode::ResetGame()
{
	AFBirdPawn* Bird = Cast<AFBirdPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());//记住了，你的操控角色在playercontroller上
	if (Bird)
	{
		Bird->ChangeState(EBirdState::EBS_Idle);
	}
	if (NotifyGS.IsBound())
	{
		NotifyGS.Broadcast(EFBGameState::FBGS_ResetGame);
	}
}

float AFBGameMode::GetSpeed()
{
	return Speed;
}

void AFBGameMode::BeginGame()
{
	//让小鸟的状态变为飞行
	AFBirdPawn* Bird = Cast<AFBirdPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());//记住了，你的操控角色在playercontroller上

	if (Bird)
	{
		Bird->ChangeState(EBirdState::EBS_Fly);
	}
}

void AFBGameMode::NewGame()
{
	ChangeState(EFBGameState::FBGS_ResetGame);
}

void AFBGameMode::ChangeState(EFBGameState::Type state)
{
	switch (state)
	{
	case EFBGameState::FBGS_Menu:
		break;
	case EFBGameState::FBGS_Gaming:
		break;
	case EFBGameState::FBGS_GameOver:
		//当游戏死亡，通知所有人游戏状态变换了
		if (NotifyGS.IsBound())
		{
			NotifyGS.Broadcast(state);
		}
		break;
	case EFBGameState::FBGS_ResetGame:
		ResetGame();
		break;
	default:
		break;
	}
}
