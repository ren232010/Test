// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FBHUD.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRD_API AFBHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	virtual void NotifyHitBoxClick(FName BoxName) override;
	virtual void NotifyHitBoxRelease(FName BoxName) override;


	void DrawFBTest();

	void HUDDoJump();

	void DrawNum(int32 Num, int32 X, int32 Y);


private:
	UPROPERTY()
	class UFont* Font;
	UPROPERTY()
	class UTexture* Texture;
	UPROPERTY()
	class UMaterial* Mat;
	UPROPERTY()
	class APlayerController* Pc;


	FVector2D MouseStartPos;
	uint8 bDrawRect;
	TArray<class UTexture*> Numbers;

};
