// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSCharacterMovementComponent.h"
#include "Player/FPSCharacter.h"




float UFPSCharacterMovementComponent::GetMaxSpeed() const
{
	float Speed = Super::GetMaxSpeed();//˵����ֱ�ӵ����˸���Ļ�ȡ����ٶȵ��߼�����
	
	//��õ�ǰ���и�����Ķ���ָ��
	AFPSCharacter* Player = Cast<AFPSCharacter>(GetOwner());

	if (Player && Player->IsIronsight())
	{
		Speed *= 0.6f;
	}
	return Speed;
}
