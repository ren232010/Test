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

	if ((CurrentTime += Delta) > FireTime)//�����ʱ������ʱ�˾Ͳ�Ҫ�ٽ��п�����
	{
		return;
	}

	if ((CurrentFireTick += Delta) >= FireInterval)//��¼����ʱ����
	{
		for (int32 i=0; i<10; i++)
		{
			ACBulletActor* Bullet = Pool->PopupBullet(FollowTarget->GetComponentLocation(), FRotator(i*36, 0, 0));//ȡ�ӵ�
			Bullet->bJustice = bJustice;
			Bullet->DoFire(5);//����
			CurrentFireTick = 0;
		}
	}

}

void FBTGroupOne::DoFire(USceneComponent* FollowTarget, FRotator Dir, int8 bJustice)
{
	FBTBase::DoFire(FollowTarget, Dir, bJustice);
}
