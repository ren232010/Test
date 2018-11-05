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
	//������Ϸ����Ĭ�Ͻ�ɫ
	DefaultPawnClass = AFBirdPawn::StaticClass();//StaticClass ���ٻ�ȡһ�������ģ���ʲ�
	//��������������Ĭ��PlayerController
	PlayerControllerClass = AFBPlayerController::StaticClass();
	//�����������е�Ĭ����Ϸ״̬
	GameStateClass = AFBGameState::StaticClass();
	//������ϷĬ�ϵ�HUD
	HUDClass = AFBHUD::StaticClass();

	Speed = 150;
}

void AFBGameMode::BeginPlay()
{
	InitFB();
}

void AFBGameMode::InitFB()
{
	//���ñ���
	auto BgActor = GetWorld()->SpawnActor<AFBgActor>(FVector(0, -100, 0), FRotator::ZeroRotator);
	//����·��
	auto LandActor = GetWorld()->SpawnActor<AFBLandActor>();
	//�����ܵ�
	auto PipeActor = GetWorld()->SpawnActor<AFBPipeActor>();
	
	//�󶨶ಥ������Ҫ�����Ϸ״̬֪ͨ�Ķ�����а�
	NotifyGS.AddUObject(LandActor, &AFBLandActor::ChangeGameStateCB);
	NotifyGS.AddUObject(PipeActor, &AFBPipeActor::ChangeGameStateCB);

}

void AFBGameMode::ResetGame()
{
	AFBirdPawn* Bird = Cast<AFBirdPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());//��ס�ˣ���Ĳٿؽ�ɫ��playercontroller��
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
	//��С���״̬��Ϊ����
	AFBirdPawn* Bird = Cast<AFBirdPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());//��ס�ˣ���Ĳٿؽ�ɫ��playercontroller��

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
		//����Ϸ������֪ͨ��������Ϸ״̬�任��
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
