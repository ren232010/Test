// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FBirdPawn.generated.h"

UENUM()
namespace EBirdState
{
	enum Type
	{
		EBS_Idle,
		EBS_Fly,
		EBS_Dead
	};
}


UCLASS()
class FLAPPYBIRD_API AFBirdPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFBirdPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Init();
	void DoJump();

	UFUNCTION()
	void OnComponentHitEvent(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ChangeState(EBirdState::Type State);
	void UpdateFace();


private:
	UPROPERTY()
	class UCameraComponent* MainCamera;  //���һ�����������Ϸ ��Ϸ�������
	UPROPERTY()
	class UPaperFlipbookComponent* BirdAnim;//���һ��������ʾС������
	UPROPERTY()
	class USoundBase* FlySound;


	TEnumAsByte<EBirdState::Type> State;


	
};
