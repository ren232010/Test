// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CHUD.generated.h"

/**
 * 
 */
UCLASS()
class FLYGAME_API ACHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void DrawHUD() override;
	
	virtual void NotifyHitBoxClick(FName BoxName) override;
	

	void DrawHPBar();


protected:
	UPROPERTY()
	class ACBossActor* Boss;
	UPROPERTY()
	class ACAirPlanePawn* Plane;
	UPROPERTY()
	class APlayerController* m_Pc;

};
