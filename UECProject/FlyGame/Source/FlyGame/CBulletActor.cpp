// Fill out your copyright notice in the Description page of Project Settings.

#include "CBulletActor.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "CGameMode.h"
#include "Engine/World.h"
#include "CBulletPool.h"
#include "CAirPlanePawn.h"
#include "CBossActor.h"


// Sets default values
ACBulletActor::ACBulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	BulletRender = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("BulletRender"));
	BulletRender->SetupAttachment(RootComp);
	//绑定overlap事件通知
	BulletRender->OnComponentBeginOverlap.AddDynamic(this, &ACBulletActor::OnComponentBeginOverlapEvent);
	//修改碰撞预设
	BulletRender->SetCollisionProfileName(TEXT("BulletProfile"));

	bFly = false;
	LifeTime = 2;
	bJustice = -1;
}

// Called when the game starts or when spawned
void ACBulletActor::BeginPlay()
{
	Super::BeginPlay();
	
	//test
	BulletRender->SetFlipbook(LoadObject<UPaperFlipbook>(NULL, TEXT("PaperFlipbook'/Game/FlyGame/Animations/Bullet/PF_Bullet_01.PF_Bullet_01'")));

}

void ACBulletActor::UpdateFly(float Delta)
{
	if (!bFly)
	{
		return;
	}
	AddActorWorldOffset(GetActorUpVector() * Speed * Delta);//朝着我自己的上方向去飞啊
	if (OffsetAngel != 0)
	{
		AddActorLocalRotation(FRotator(OffsetAngel, 0, 0));
	}


	if ((CurrentTick += Delta) > LifeTime)//说明在世界中的存在时间已经超时了，应该将自己放回到子弹池中
	{
		BackPool();
	}
}

void ACBulletActor::OnComponentBeginOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ACAirPlanePawn* Pawn = Cast<ACAirPlanePawn>(OtherActor);
	if (Pawn )
	{
		if (bJustice == 0)
		{
		//	UE_LOG(LogTemp, Log, TEXT("友军中弹   "));
			Pawn->CurrentHP--;

		}
	}
	else
	{
		if (bJustice == 1)
		{
			ACBossActor* Boss = Cast<ACBossActor>(OtherActor);
			if (Boss)
			{
				Boss->CurrentHP--;
			}
		}
	}


	
	//BackPool();
}

void ACBulletActor::BackPool()
{
	ACGameMode* Gm = Cast<ACGameMode>(GetWorld()->GetAuthGameMode());
	if (Gm)
	{
		Gm->GetBulletPool()->GiveBackBullet(this);//归还我自己
	}
	bFly = false;
	BulletRender->SetVisibility(false);
	BulletRender->SetGenerateOverlapEvents(false);
}

// Called every frame
void ACBulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateFly(DeltaTime);
}

void ACBulletActor::DoFire(float offsetAngel, float Speed /*= 1200*/)
{
	this->Speed = Speed;
	bFly = true;
	CurrentTick = 0;
	BulletRender->SetVisibility(true);
	BulletRender->SetGenerateOverlapEvents(true);
	this->OffsetAngel = offsetAngel;
}

