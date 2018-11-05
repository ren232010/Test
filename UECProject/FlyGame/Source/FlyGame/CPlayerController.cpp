// Fill out your copyright notice in the Description page of Project Settings.

#include "CPlayerController.h"




ACPlayerController::ACPlayerController()
{
	bShowMouseCursor = true;//显示鼠标光标
	bEnableClickEvents = true;//开启点击事件响应
}

void ACPlayerController::BeginPlay()
{
	Super::BeginPlay();//注意一定要调用父类的Beginplay



}
