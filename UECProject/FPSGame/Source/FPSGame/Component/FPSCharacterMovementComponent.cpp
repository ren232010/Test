// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSCharacterMovementComponent.h"
#include "Player/FPSCharacter.h"




float UFPSCharacterMovementComponent::GetMaxSpeed() const
{
	float Speed = Super::GetMaxSpeed();//说明我直接调用了父类的获取最大速度的逻辑函数
	
	//获得当前持有该组件的对象指针
	AFPSCharacter* Player = Cast<AFPSCharacter>(GetOwner());

	if (Player && Player->IsIronsight())
	{
		Speed *= 0.6f;
	}
	return Speed;
}
