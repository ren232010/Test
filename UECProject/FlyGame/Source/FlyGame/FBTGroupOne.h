// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FBTBase.h"

/**
 * 
 */
class FLYGAME_API FBTGroupOne : public FBTBase
{
public:
	FBTGroupOne(ACBulletPool* Pool, float fireTime, float fireInteral);
	~FBTGroupOne();

	virtual void UpdateBulletGroup(float Delta) override;
	virtual void DoFire(USceneComponent* FollowTarget, FRotator Dir, int8 bJustice) override;

};
