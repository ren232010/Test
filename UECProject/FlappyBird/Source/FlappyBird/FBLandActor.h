// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FBLandActor.generated.h"

UCLASS()
class FLAPPYBIRD_API AFBLandActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFBLandActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Init();
	void UpdateLandPartOffset(float Delta);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ChangeGameStateCB(int32 State);
	
private:
	UPROPERTY()
	class UPaperSpriteComponent* LandOne;
	UPROPERTY()
	class UPaperSpriteComponent* LandTwo;

private:
	UPROPERTY()
	class AFBGameMode* FbGM;

	uint8 bRun : true;


	
};
