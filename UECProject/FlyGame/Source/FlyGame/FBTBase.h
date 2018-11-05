// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"




/**
 * 这是弹幕基类，用来进行弹幕类别衍生
 */
class FLYGAME_API FBTBase
{

protected:
	//UPROPERTY()
	class ACBulletPool* Pool;
	class USceneComponent* FollowTarget;

	float FireTime;//持续发射时间
	float FireInterval;//发射间隔

	float CurrentTime;//记录总时长
	float CurrentFireTick;//记录发射间隔时长

	int8 bJustice;

public:
	//FBTBase();
	~FBTBase();
	FBTBase(ACBulletPool* Pool, float fireTime, float fireInteral);

public:
	virtual void UpdateBulletGroup(float Delta);
	virtual void DoFire(USceneComponent* FollowTarget, FRotator Dir, int8 bJustice = -1);


};
