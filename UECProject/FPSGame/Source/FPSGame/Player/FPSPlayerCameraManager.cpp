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
	//FOV过度调整逻辑
	//1.如何获得到Character 
	//PCOwner获取当前持有此cameramanager的playercontroller
	AFPSCharacter* Player = Cast<AFPSCharacter>(PCOwner->GetPawn());//获取当前的操控角色
	if (!Player)
	{
		return;
	}
	float TargetFOV = Player->IsIronsight() ? IronsightFOV : NormalFOV;

	DefaultFOV = FMath::Lerp<float>(DefaultFOV, TargetFOV, 0.2f);
	SetFOV(DefaultFOV);
}
