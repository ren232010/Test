// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSGameMode.h"
#include "ConstructorHelpers.h"
#include "Player/FPSCharacter.h"
#include "Player/FPSPlayerController.h"
#include "HUD/FPSHUD.h"




AFPSGameMode::AFPSGameMode()
{
	static ConstructorHelpers::FClassFinder<AFPSCharacter> PlayerClass(TEXT("Blueprint'/Game/FPS/Blueprints/Player/BP_Character.BP_Character_C'"));

	DefaultPawnClass = PlayerClass.Class;
	PlayerControllerClass = AFPSPlayerController::StaticClass();

	HUDClass = AFPSHUD::StaticClass();
}
