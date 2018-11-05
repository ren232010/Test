// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBulletActor.generated.h"

UCLASS()
class FLYGAME_API ACBulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACBulletActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void UpdateFly(float Delta);

	UFUNCTION()
	void OnComponentBeginOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	void BackPool();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DoFire(float offsetAngel = 0, float Speed = 1200);


protected:
	UPROPERTY()
	class UPaperFlipbookComponent* BulletRender;
	
	float Speed;
	uint8 bFly;

	float LifeTime;
	float CurrentTick;
	float OffsetAngel;
public:
	int8 bJustice;

};
