// Fill out your copyright notice in the Description page of Project Settings.

#include "FBTBase.h"
#include "CBulletPool.h"
#include "Components/SceneComponent.h"
#include "CBulletActor.h"



FBTBase::FBTBase(ACBulletPool* Pool, float fireTime, float fireInteral)
{
	this->FireTime = fireTime;
	this->FireInterval = fireInteral;
	this->Pool = Pool;
}

/*
FBTBase::FBTBase()
{

}*/

FBTBase::~FBTBase()
{
}

void FBTBase::UpdateBulletGroup(float Delta)
{
	if (!Pool || !FollowTarget)
	{
		return;
	}
	if ((CurrentTime += Delta) > FireTime)//检查总时长，超时了就不要再进行开火了
	{
		return;
	}
	if ((CurrentFireTick += Delta) >= FireInterval)//记录开火时间间隔
	{
		ACBulletActor* Bullet = Pool->PopupBullet(FollowTarget->GetComponentLocation());//取子弹
		Bullet->bJustice = bJustice;
		Bullet->DoFire();//开火
		
		CurrentFireTick = 0;
	}
}

void FBTBase::DoFire(USceneComponent* FollowTarget, FRotator Dir, int8 bJustice)
{
	this->FollowTarget = FollowTarget;
	CurrentFireTick = FireInterval;//保证该弹幕在启动的时候会进行子弹发射
	CurrentTime = 0;
	this->bJustice = bJustice;
}



