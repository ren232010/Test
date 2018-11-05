// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FBPipeActor.generated.h"


USTRUCT(BlueprintType)
struct FPipeGroup
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY()
	class UPaperSpriteComponent* Up;
	UPROPERTY()
	class UPaperSpriteComponent* Down;

	void RandomPipePos();
	void UpdatePipePos();

	float OffsetX;

};



UCLASS()
class FLAPPYBIRD_API AFBPipeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFBPipeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Init();
	void UpdatePipeGroupPos(float Delta);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ChangeGameStateCB(int32 State);

private:
	UPROPERTY()
	TArray<FPipeGroup> PipeGroup;//使用容器存储管道组
	
	UPROPERTY()
	class AFBGameMode* pGm;
	//C++新初始化方式 为变量进行赋值
	uint8 bRun : true;
};
