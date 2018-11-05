// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CAirPlanePawn.generated.h"

UCLASS()
class FLYGAME_API ACAirPlanePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACAirPlanePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveUp(float Value);
	void MoveRight(float Value);
	void MousePickupPos();
	void Fire();


	void ClampAirPlane();

	void MoveToPickupPos(float Delta);
	void FollowTargetToMove(float Delta);

	//触摸事件的回调函数
	void OnTouchByFingerPressed(ETouchIndex::Type Type, FVector Pos);
	void OnTouchByFingerRepeat(ETouchIndex::Type Type, FVector Pos);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	class UPaperFlipbookComponent* GetPlaneRenderComponent();

	
protected:
	UPROPERTY(VisibleAnywhere)
	class UPaperFlipbookComponent* AirPlane;
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* MainCamera;
	UPROPERTY(EditDefaultsOnly, Category="FlyGame")
	float MoveSpeed;
	UPROPERTY()
	class APlayerController* m_Pc;
	UPROPERTY(VisibleAnywhere)
	class UEmitterComponent* EmitterComp;
	UPROPERTY(VisibleAnywhere)
	class USpaceEmitterComponent* SpaceEmitterComp;

	
	FVector LeftTop;
	FVector RightBottom;
	FVector PickupPos;
public:
	int32 CurrentHP;
	int32 MaxHP;
};
