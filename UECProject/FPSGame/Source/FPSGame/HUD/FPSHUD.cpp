// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSHUD.h"
#include "Engine/Canvas.h"




void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();
	//绘制准星

	float ScreenCenterX = Canvas->ClipX / 2;
	float ScreenCenterY = Canvas->ClipY / 2;

	//准星长度15 偏离中心30
	DrawLine(ScreenCenterX, ScreenCenterY - 15, ScreenCenterX, ScreenCenterY - 5, FLinearColor::Green);
	DrawLine(ScreenCenterX + 5, ScreenCenterY, ScreenCenterX + 15, ScreenCenterY, FLinearColor::Green);
	DrawLine(ScreenCenterX, ScreenCenterY + 5, ScreenCenterX, ScreenCenterY + 15, FLinearColor::Green);
	DrawLine(ScreenCenterX - 15, ScreenCenterY, ScreenCenterX - 5, ScreenCenterY, FLinearColor::Green);
	
}
