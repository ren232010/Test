// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "FPSPlayerCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API AFPSPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
protected:
	AFPSPlayerCameraManager();
	virtual void UpdateCamera(float DeltaTime) override;
	
protected:
	float NormalFOV;
	float IronsightFOV;

};
