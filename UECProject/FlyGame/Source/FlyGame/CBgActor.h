// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBgActor.generated.h"

UCLASS()
class FLYGAME_API ACBgActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACBgActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetBgSpeed(float Speed);
	void SetBgTexture(class UTexture* Texture);


protected:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* BgMesh;
	UPROPERTY()
	class UMaterialInstanceDynamic* DynamicMat;
	
};
