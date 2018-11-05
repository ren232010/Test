// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FPSCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UFPSCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
protected:

	virtual float GetMaxSpeed() const override;
	
	
};
