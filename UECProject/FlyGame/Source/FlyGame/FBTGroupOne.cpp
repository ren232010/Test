// Fill out your copyright notice in the Description page of Project Settings.

#include "FBTGroupOne.h"
#include "CBulletActor.h"
#include "CBulletPool.h"

FBTGroupOne::FBTGroupOne(ACBulletPool* Pool, float fireTime, float fireInteral) : FBTBase(Pool, fireTime, fireInteral)
{
}

FBTGroupOne::~FBTGroupOne()
{
}

void FBTGroupOne::UpdateBulletGroup(float Delta)
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
		for (int32 i=0; i<10; i++)
		{
			ACBulletActor* Bullet = Pool->PopupBullet(FollowTarget->GetComponentLocation(), FRotator(i*36, 0, 0));//取子弹
			Bullet->bJustice = bJustice;
			Bullet->DoFire(5);//开火
			CurrentFireTick = 0;
		}
	}

}

void FBTGroupOne::DoFire(USceneComponent* FollowTarget, FRotator Dir, int8 bJustice)
{
	FBTBase::DoFire(FollowTarget, Dir, bJustice);
}
