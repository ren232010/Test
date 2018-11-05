// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceEmitterComponent.h"
#include "CAirPlanePawn.h"
#include "CGameMode.h"
#include "Engine/World.h"
#include "CBulletActor.h"
#include "CBulletPool.h"
#include "FBTBase.h"
#include "FBTGroupOne.h"
#include "Paths.h"

// Sets default values for this component's properties
USpaceEmitterComponent::USpaceEmitterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpaceEmitterComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	Gm = Cast<ACGameMode>(GetWorld()->GetAuthGameMode());
}




// Called every frame
void USpaceEmitterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*if (bFire)
	{
		if (Gm)
		{
			Angel += DeltaTime;
			if (Angel > 0.1f)
			{
				ACBulletActor* Buttle = Gm->GetBulletPool()->PopupBullet(GetComponentLocation(), FRotator(FireIndex * 10, 0, 0));
				Buttle->DoFire();
				
				FireIndex++;
				Angel = 0;
			}
		}
	}*/

	if (BulletGroup)
	{
		BulletGroup->UpdateBulletGroup(DeltaTime);
	}

	// ...
}

void USpaceEmitterComponent::DoFire(EBGType::Type type, float FireTime, float FireInterval)
{
	if (!BulletGroup)
	{
		switch (type)
		{
		case EBGType::EBG_Normal:
			BulletGroup = MakeShareable(new FBTBase((Gm ? Gm->GetBulletPool() : nullptr), FireTime, FireInterval));
			break;
		case EBGType::EBG_Yuan:
			BulletGroup = MakeShareable(new FBTGroupOne((Gm ? Gm->GetBulletPool() : nullptr), FireTime, FireInterval));
			break;
		default:
			break;
		}
	}

	ACAirPlanePawn* Pawn = Cast<ACAirPlanePawn>(GetOwner());
	BulletGroup->DoFire(this, FRotator::ZeroRotator, Pawn ? 1 : 0);
}

