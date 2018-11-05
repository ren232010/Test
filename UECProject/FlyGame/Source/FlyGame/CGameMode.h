// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "CGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FLYGAME_API ACGameMode : public AGameMode
{
	GENERATED_BODY()

		ACGameMode();
protected:

	virtual void BeginPlay() override;


protected:
	UPROPERTY()
	class ACBgActor* BgActor;
	UPROPERTY()
	class ACBulletPool* Pool;
	UPROPERTY()
	class ACBossActor* Boss;

	int32 CurrentLevel;
public:
	void SetBgActor(ACBgActor* Bg);

	void SetBgSpeed(float Speed);
	void ChangeGameLevel(int32 Level);

	ACBulletPool* GetBulletPool();

	void SetBoss(ACBossActor* Boss);

	ACBossActor* GetBoss();

};
