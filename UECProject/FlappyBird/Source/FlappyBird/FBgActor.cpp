// Fill out your copyright notice in the Description page of Project Settings.

#include "FBgActor.h"
#include "Components/SceneComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSprite.h"
#include "ConstructorHelpers.h"
#include "Components/AudioComponent.h"


// Sets default values
AFBgActor::AFBgActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* RootCom = CreateDefaultSubobject<USceneComponent>(TEXT("RootCom"));
	SetRootComponent(RootCom);

	BgSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteRender"));
	BgSprite->SetupAttachment(RootCom);

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));//创建音频组件
	//构造函数加载方式
	static ConstructorHelpers::FObjectFinder<USoundBase> Sound(TEXT("SoundWave'/Game/FlappyBird/Sounds/bgm.bgm'"));
	AudioComp->SetSound(Sound.Object);
	//AudioComp->bAlwaysPlay = true;//

}

// Called when the game starts or when spawned
void AFBgActor::BeginPlay()
{
	Super::BeginPlay();
	//加载Sprite图片
	RandomBgImage();
}

void AFBgActor::RandomBgImage()
{
	//随即产生更换背景图
	TCHAR* FileName = FMath::RandBool() ? (TEXT("PaperSprite'/Game/FlappyBird/Textures/BG/bg_day_Sprite.bg_day_Sprite'")) : (TEXT("PaperSprite'/Game/FlappyBird/Textures/BG/bg_night_Sprite.bg_night_Sprite'"));

	UPaperSprite* Bg = LoadObject<UPaperSprite>(NULL, FileName);
	if (Bg && BgSprite)
	{
		BgSprite->SetSprite(Bg);
	}
}

// Called every frame
void AFBgActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

