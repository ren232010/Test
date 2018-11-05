// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBulletPool.generated.h"

UCLASS()
class FLYGAME_API ACBulletPool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACBulletPool();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void GiveBackBullet(class ACBulletActor* Bullet);
	class ACBulletActor* PopupBullet(FVector Pos = FVector::ZeroVector, FRotator Rot = FRotator::ZeroRotator);


private:
	UPROPERTY()
	TArray<class ACBulletActor*> BulletPool;

		
	
};
