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
	if ((CurrentTime += Delta) > FireTime)//�����ʱ������ʱ�˾Ͳ�Ҫ�ٽ��п�����
	{
		return;
	}
	if ((CurrentFireTick += Delta) >= FireInterval)//��¼����ʱ����
	{
		ACBulletActor* Bullet = Pool->PopupBullet(FollowTarget->GetComponentLocation());//ȡ�ӵ�
		Bullet->bJustice = bJustice;
		Bullet->DoFire();//����
		
		CurrentFireTick = 0;
	}
}

void FBTBase::DoFire(USceneComponent* FollowTarget, FRotator Dir, int8 bJustice)
{
	this->FollowTarget = FollowTarget;
	CurrentFireTick = FireInterval;//��֤�õ�Ļ��������ʱ�������ӵ�����
	CurrentTime = 0;
	this->bJustice = bJustice;
}



