// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSAnimInstance.h"
#include "Player/FPSCharacter.h"
#include "GameFramework/Controller.h"




void UFPSAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	//获取动画从属角色
	m_Player = Cast<AFPSCharacter>(TryGetPawnOwner());
}

void UFPSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!m_Player)
	{
		return;
	}
	//获取玩家当前的速度 从速度向量上获取长度就是偏移速度值
	Speed = m_Player->GetVelocity().Size2D();
	//if (Speed)
	//{
	//	//获取玩家的移动方向
	//	FVector MoveDir = m_Player->GetVelocity().GetSafeNormal();

	//	FVector PlayerForward = m_Player->GetActorForwardVector();
	//	FVector PlayerRight = m_Player->GetActorRightVector();

	//	//单位向量点乘，获取移动方向权重值
	//	MoveForward = FVector::DotProduct(MoveDir, PlayerForward);
	//	MoveRight = FVector::DotProduct(MoveDir, PlayerRight);
	//}
	//else
	//{
	//	MoveForward = 0;
	//	MoveRight = 0;
	//}
	//m_Player->GetVelocity().dir
	//获取移动方向
	//FRotator MoveRot = m_Player->GetVelocity().Rotation();//将移动速度转换成为欧拉角
	//FRotator PlayerRot = m_Player->GetActorRotation();//获取当前玩家的欧拉角
	//Direction = MoveRot.Yaw - PlayerRot.Yaw;
	
	//m_Player->GetVelocity().ToDirectionAndLength()

	//FRotator::NormalizeAxis(Direction)
	//Direction = Direction > 180 ? 360 - Direction : Direction;

	Direction = CalculateDirection(m_Player->GetVelocity(), m_Player->GetBaseAimRotation());//使用给定的移动向量和基准角色转向欧拉角，计算位移方向值（-180-180）
	/*AimPitch = m_Player->GetControlRotation().Pitch > 180 ? m_Player->GetControlRotation().Pitch - 360 : m_Player->GetControlRotation().Pitch;
	FRotator Rot = m_Player->GetControlRotation() - m_Player->GetActorRotation();
	
	AimYaw = Rot.Yaw > 180 ? Rot.Yaw - 360 : Rot.Yaw;*/

	
	FTransform PlayerTransformWS = m_Player->ActorToWorld();//将自身的transfrom转为世界的
	FVector AimDirWS = m_Player->GetBaseAimRotation().Vector();//瞄准向量（世界单位）
	FVector AimDirLW = PlayerTransformWS.InverseTransformVectorNoScale(AimDirWS);//反向逆推瞄准向量到自身 得到一个自身的朝向向量
	FRotator Rot = AimDirLW.Rotation();//将自身的一个向量转换成为欧拉角

	AimPitch = Rot.Pitch;
	AimYaw = Rot.Yaw;
	bIronsight = m_Player->IsIronsight();

	bCrouch = m_Player->bIsCrouched;
}
