// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSAnimInstance.h"
#include "Player/FPSCharacter.h"
#include "GameFramework/Controller.h"




void UFPSAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	//��ȡ����������ɫ
	m_Player = Cast<AFPSCharacter>(TryGetPawnOwner());
}

void UFPSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!m_Player)
	{
		return;
	}
	//��ȡ��ҵ�ǰ���ٶ� ���ٶ������ϻ�ȡ���Ⱦ���ƫ���ٶ�ֵ
	Speed = m_Player->GetVelocity().Size2D();
	//if (Speed)
	//{
	//	//��ȡ��ҵ��ƶ�����
	//	FVector MoveDir = m_Player->GetVelocity().GetSafeNormal();

	//	FVector PlayerForward = m_Player->GetActorForwardVector();
	//	FVector PlayerRight = m_Player->GetActorRightVector();

	//	//��λ������ˣ���ȡ�ƶ�����Ȩ��ֵ
	//	MoveForward = FVector::DotProduct(MoveDir, PlayerForward);
	//	MoveRight = FVector::DotProduct(MoveDir, PlayerRight);
	//}
	//else
	//{
	//	MoveForward = 0;
	//	MoveRight = 0;
	//}
	//m_Player->GetVelocity().dir
	//��ȡ�ƶ�����
	//FRotator MoveRot = m_Player->GetVelocity().Rotation();//���ƶ��ٶ�ת����Ϊŷ����
	//FRotator PlayerRot = m_Player->GetActorRotation();//��ȡ��ǰ��ҵ�ŷ����
	//Direction = MoveRot.Yaw - PlayerRot.Yaw;
	
	//m_Player->GetVelocity().ToDirectionAndLength()

	//FRotator::NormalizeAxis(Direction)
	//Direction = Direction > 180 ? 360 - Direction : Direction;

	Direction = CalculateDirection(m_Player->GetVelocity(), m_Player->GetBaseAimRotation());//ʹ�ø������ƶ������ͻ�׼��ɫת��ŷ���ǣ�����λ�Ʒ���ֵ��-180-180��
	/*AimPitch = m_Player->GetControlRotation().Pitch > 180 ? m_Player->GetControlRotation().Pitch - 360 : m_Player->GetControlRotation().Pitch;
	FRotator Rot = m_Player->GetControlRotation() - m_Player->GetActorRotation();
	
	AimYaw = Rot.Yaw > 180 ? Rot.Yaw - 360 : Rot.Yaw;*/

	
	FTransform PlayerTransformWS = m_Player->ActorToWorld();//�������transfromתΪ�����
	FVector AimDirWS = m_Player->GetBaseAimRotation().Vector();//��׼���������絥λ��
	FVector AimDirLW = PlayerTransformWS.InverseTransformVectorNoScale(AimDirWS);//����������׼���������� �õ�һ������ĳ�������
	FRotator Rot = AimDirLW.Rotation();//�������һ������ת����Ϊŷ����

	AimPitch = Rot.Pitch;
	AimYaw = Rot.Yaw;
	bIronsight = m_Player->IsIronsight();

	bCrouch = m_Player->bIsCrouched;
}
