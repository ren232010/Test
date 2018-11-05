// Fill out your copyright notice in the Description page of Project Settings.

#include "CBgActor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "CGameMode.h"
#include "Engine/Texture.h"


// Sets default values
ACBgActor::ACBgActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);

	BgMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BgRender"));
	BgMesh->SetupAttachment(RootComp);
}

// Called when the game starts or when spawned
void ACBgActor::BeginPlay()
{
	Super::BeginPlay();
	DynamicMat = BgMesh->CreateDynamicMaterialInstance(0);
	

	ACGameMode* Gm = Cast<ACGameMode>(GetWorld()->GetAuthGameMode());
	if (Gm)
	{
		Gm->SetBgActor(this);
	}
}

// Called every frame
void ACBgActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACBgActor::SetBgSpeed(float Speed)
{
	if (DynamicMat)
	{
		DynamicMat->SetScalarParameterValue(TEXT("Speed"), Speed);
	}
}

void ACBgActor::SetBgTexture(UTexture* Texture)
{
	if (DynamicMat)
	{
		DynamicMat->SetTextureParameterValue(TEXT("BG"), Texture);
	}
}

