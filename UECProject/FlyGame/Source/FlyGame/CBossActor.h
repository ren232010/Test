// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceEmitterComponent.h"
#include "GameFramework/Actor.h"
#include "CBossActor.generated.h"


USTRUCT(BlueprintType)
struct FBossLevel
{
	GENERATED_USTRUCT_BODY();

	EBGType::Type Type;//
	float FireTime;
	float FireInterval;

};


UCLASS()
class FLYGAME_API ACBossActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACBossActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void LoadBossLevel();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
protected:
	UPROPERTY()
	class UPaperSpriteComponent* SpriteRender;
	UPROPERTY()
	class USpaceEmitterComponent* EmitterComp;


public:
	int32 CurrentHP;
	int32 MaxHP;

protected:
	TArray<TSharedPtr<FBossLevel>> BossLevel;

	int32 CurrentBL;

};
