// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSPlayerController.h"
#include "FPSPlayerCameraManager.h"




AFPSPlayerController::AFPSPlayerController()
{
	PlayerCameraManagerClass = AFPSPlayerCameraManager::StaticClass();
}
