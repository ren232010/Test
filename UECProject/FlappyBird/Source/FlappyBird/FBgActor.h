// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FBgActor.generated.h"

UCLASS()
class FLAPPYBIRD_API AFBgActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFBgActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void RandomBgImage();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY()
	class UPaperSpriteComponent* BgSprite;
	UPROPERTY()
	class UAudioComponent* AudioComp;//音频组件用来播放声音
	
	
};
