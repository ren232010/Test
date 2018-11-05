// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FBGameMode.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateNotifyGameState, int32);

UENUM()
namespace EFBGameState
{
	enum Type
	{
		FBGS_Menu,
		FBGS_Gaming,
		FBGS_GameOver,
		FBGS_ResetGame
	};
}


/**
 * 
 */
UCLASS()
class FLAPPYBIRD_API AFBGameMode : public AGameMode
{
	GENERATED_BODY()

		AFBGameMode();
	
protected:

	void BeginPlay() override;
	void InitFB();
	void ResetGame();

private:
	
	float Speed;

	FDelegateNotifyGameState NotifyGS;

	TEnumAsByte<EFBGameState::Type> CurrentState;



public:

	float GetSpeed();

	UFUNCTION(Exec)
	void BeginGame();
	UFUNCTION(Exec)
	void NewGame();

	void ChangeState(EFBGameState::Type state);


};
