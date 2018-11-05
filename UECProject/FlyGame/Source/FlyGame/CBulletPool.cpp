// Fill out your copyright notice in the Description page of Project Settings.

#include "CBulletPool.h"
#include "CBulletActor.h"
#include "Engine/World.h"


// Sets default values
ACBulletPool::ACBulletPool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACBulletPool::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACBulletPool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACBulletPool::GiveBackBullet(class ACBulletActor* Bullet)
{
	if (!Bullet)
	{
		return;
	}
	Bullet->bJustice = -1;
	BulletPool.Add(Bullet);
}

ACBulletActor* ACBulletPool::PopupBullet(FVector Pos /*= FVector::ZeroVector*/, FRotator Rot)
{
	ACBulletActor* Bullet = BulletPool.Num() ? BulletPool.Pop() : NULL;//������ȡ����һ��Ҫ�������ڳ����Ƴ�
	if (!Bullet)//���û��ȡ��������Ҳ��˵���������ǿյ�
	{
		Bullet = GetWorld()->SpawnActor<ACBulletActor>(Pos, Rot);
	}
	Bullet->SetActorLocation(Pos);
	Bullet->SetActorRotation(Rot);
	return Bullet;
}

