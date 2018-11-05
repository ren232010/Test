// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSPlayerCameraManager.h"
#include "FPSCharacter.h"
#include "GameFramework/PlayerController.h"




AFPSPlayerCameraManager::AFPSPlayerCameraManager()
{
	NormalFOV = 90.0f;
	IronsightFOV = 65.0f;
}

void AFPSPlayerCameraManager::UpdateCamera(float DeltaTime)
{
	Super::UpdateCamera(DeltaTime);
	//FOV���ȵ����߼�
	//1.��λ�õ�Character 
	//PCOwner��ȡ��ǰ���д�cameramanager��playercontroller
	AFPSCharacter* Player = Cast<AFPSCharacter>(PCOwner->GetPawn());//��ȡ��ǰ�Ĳٿؽ�ɫ
	if (!Player)
	{
		return;
	}
	float TargetFOV = Player->IsIronsight() ? IronsightFOV : NormalFOV;

	DefaultFOV = FMath::Lerp<float>(DefaultFOV, TargetFOV, 0.2f);
	SetFOV(DefaultFOV);
}
