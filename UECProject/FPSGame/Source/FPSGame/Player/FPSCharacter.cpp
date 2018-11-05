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
	//������ʼ����������SetDefaultSubobjectClass�滻ԭ������Ĭ�ϵ����  �������滻Ŀ����������ƣ��ı�������ƣ�
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//��װ����
	SpringArm->SetupAttachment(GetRootComponent());//���� Pawn�Ƿ������Ҫ����
	//�������
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
	//��ȡcontroller��������
	FRotator Rot(0, GetControlRotation().Yaw, 0);
	//������ת�����ھ����л�ȡ����������
	FVector Dir = FRotationMatrix(Rot).GetUnitAxis(EAxis::X);
	//���λ��
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
