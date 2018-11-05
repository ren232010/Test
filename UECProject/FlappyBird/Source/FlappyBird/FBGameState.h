// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "FBGameState.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRD_API AFBGameState : public AGameState
{
	GENERATED_BODY()
	
private:
	int32 Score;

public:
	void AddScore();
	int32 GetScore();
	void ResetScore();

	
};
