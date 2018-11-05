// Fill out your copyright notice in the Description page of Project Settings.

#include "CHUD.h"
#include "Engine/Canvas.h"
#include "CGameMode.h"
#include "CBgActor.h"
#include "CBossActor.h"
#include "CAirPlanePawn.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperFlipbookComponent.h"



void ACHUD::DrawHUD()
{
	Super::DrawHUD();


	DrawHPBar();



	AddHitBox(FVector2D(0, 0), FVector2D(100, 100), TEXT("ok"), true);
	RenderHitBoxes(Canvas->Canvas);
}

void ACHUD::NotifyHitBoxClick(FName BoxName)
{
	ACGameMode* Gm = Cast<ACGameMode>(GetWorld()->GetAuthGameMode());
	if (Gm)
	{
		Gm->ChangeGameLevel(2);
		Gm->SetBgSpeed(-0.1f);
	}

}

void ACHUD::DrawHPBar()
{
	//bossµÄ
	if (!Boss)
	{
		ACGameMode* Gm = Cast<ACGameMode>(GetWorld()->GetAuthGameMode());
		if (Gm)
		{
			Boss = Gm->GetBoss();
		}
	}
	if (Boss)
	{
		DrawRect(FLinearColor::Gray, 50, 50, Canvas->ClipX - 50, 50);
		DrawRect(FLinearColor::Green, 50, 50, (Canvas->ClipX - 50) * Boss->CurrentHP / Boss->MaxHP, 50);
	}

	//Íæ¼ÒµÄ
	if (!Plane)
	{
		Plane = Cast<ACAirPlanePawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}
	if (!m_Pc)
	{
		m_Pc = GetWorld()->GetFirstPlayerController();
	}

	if (Plane && m_Pc)
	{
		FVector2D Pos;
		m_Pc->ProjectWorldLocationToScreen(Plane->GetPlaneRenderComponent()->GetComponentLocation(), Pos);
		
		DrawRect(FLinearColor::Gray, Pos.X, Pos.Y, 100, 10);
		DrawRect(FLinearColor::Green, Pos.X, Pos.Y, 100.0f * Plane->CurrentHP / Plane->MaxHP, 10);
	}



}
