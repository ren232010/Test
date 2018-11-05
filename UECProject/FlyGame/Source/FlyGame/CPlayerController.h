// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FLYGAME_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()

		ACPlayerController();

protected:
	virtual void BeginPlay() override;
	
	
};
