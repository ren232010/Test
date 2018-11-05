// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FBSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRD_API UFBSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	int32 Num;
	UPROPERTY()
	FString SName;
	UPROPERTY()
	TArray<int32> Array;
	UPROPERTY()
	bool bRun;

	
};
