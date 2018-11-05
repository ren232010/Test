// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SpaceEmitterComponent.generated.h"


namespace EBGType
{
	enum Type
	{
		EBG_Normal,
		EBG_Yuan
	};
}



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FLYGAME_API USpaceEmitterComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpaceEmitterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void DoFire(EBGType::Type type = EBGType::EBG_Normal, float FireTime = 5, float FireInterval = 1);
		

protected:
	UPROPERTY()
	class ACGameMode* Gm;

	float Angel;
	uint8 bFire;
	int32 FireIndex;
	
	TSharedPtr<class FBTBase> BulletGroup;

};
