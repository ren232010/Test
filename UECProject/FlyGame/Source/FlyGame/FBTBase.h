// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"




/**
 * ���ǵ�Ļ���࣬�������е�Ļ�������
 */
class FLYGAME_API FBTBase
{

protected:
	//UPROPERTY()
	class ACBulletPool* Pool;
	class USceneComponent* FollowTarget;

	float FireTime;//��������ʱ��
	float FireInterval;//������

	float CurrentTime;//��¼��ʱ��
	float CurrentFireTick;//��¼������ʱ��

	int8 bJustice;

public:
	//FBTBase();
	~FBTBase();
	FBTBase(ACBulletPool* Pool, float fireTime, float fireInteral);

public:
	virtual void UpdateBulletGroup(float Delta);
	virtual void DoFire(USceneComponent* FollowTarget, FRotator Dir, int8 bJustice = -1);


};
