// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Component/FPSCharacterMovementComponent.h"


// Sets default values
AFPSCharacter::AFPSCharacter(const FObjectInitializer& Initializer) 
	: Super(Initializer.SetDefaultSubobjectClass<UFPSCharacterMovementComponent>(AFPSCharacter::CharacterMovementComponentName))
	//借助初始化对象器，SetDefaultSubobjectClass替换原对象中默认的组件  参数：替换目标组件的名称（文本标记名称）
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//安装吊臂
	SpringArm->SetupAttachment(GetRootComponent());//存疑 Pawn是否可以需要测试
	//构建相机
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(SpringArm);


	bIronsight = false;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
}



// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AFPSCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AFPSCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AFPSCharacter::Turn);

	PlayerInputComponent->BindAction(TEXT("IronSight"), IE_Pressed, this, &AFPSCharacter::IronSight);
	PlayerInputComponent->BindAction(TEXT("IronSight"), IE_Released, this, &AFPSCharacter::IronSight);

	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &AFPSCharacter::ChangeCrouch);
	//Crouch();

}


bool AFPSCharacter::IsIronsight()
{
	return bIronsight;
}

void AFPSCharacter::MoveForward(float Value)
{
	if (Value == 0)
	{
		return;
	}
	//AddMovementInput(GetActorForwardVector() * Value);
	//获取controller的正方向
	FRotator Rot(0, GetControlRotation().Yaw, 0);
	//构建旋转矩阵，在矩阵中获取正方向向量
	FVector Dir = FRotationMatrix(Rot).GetUnitAxis(EAxis::X);
	//添加位移
	AddMovementInput(Dir * Value);

}

void AFPSCharacter::MoveRight(float Value)
{
	if (Value == 0)
	{
		return;
	}
	//AddMovementInput(GetActorRightVector() * Value);
	FRotator Rot(0, GetControlRotation().Yaw, 0);
	FVector Dir = FRotationMatrix(Rot).GetUnitAxis(EAxis::Y);
	AddMovementInput(Dir * Value);
}

void AFPSCharacter::LookUp(float Value)
{
	if (Value == 0)
	{
		return;
	}

	//AddActorWorldRotation(FRotator(3 * Value, 0, 0));
	AddControllerPitchInput(Value);
}

void AFPSCharacter::Turn(float Value)
{
	if (Value == 0)
	{
		return;
	}
	//AddActorWorldRotation(FRotator(0, 3 * Value, 0));
	AddControllerYawInput(Value);
}

void AFPSCharacter::IronSight()
{
	bIronsight = !bIronsight;
}

void AFPSCharacter::ChangeCrouch()
{
	if (bIsCrouched)
	{
		UnCrouch();
	}
	else
	{
		Crouch();
	}

}
