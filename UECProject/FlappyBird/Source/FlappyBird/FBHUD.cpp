// Fill out your copyright notice in the Description page of Project Settings.

#include "FBHUD.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "Engine/Texture.h"
#include "Materials/Material.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "FBSaveGame.h"
#include "Kismet/GameplayStatics.h"




void AFBHUD::DrawHUD()
{
	Super::DrawHUD();//必须要加上这行代码 蓝图中的HUD工作和点击响应都需要使用父类的DrawHUD函数

	DrawFBTest();

	/*if (Pc->WasInputKeyJustPressed(EKeys::Q))
	{
		UE_LOG(LogTemp, Log, TEXT("halou"));
	}

	float X;
	float Y;
	Pc->GetMousePosition(X, Y);*/

	AddHitBox(FVector2D(0, 0), FVector2D(100, 100), TEXT("Save"), true, 0);
	AddHitBox(FVector2D(0, 100), FVector2D(100, 100), TEXT("Load"), true, 0);

	//这是一个测试代码，用来绘制碰撞框位置信息的
	RenderHitBoxes(Canvas->Canvas);
}

void AFBHUD::BeginPlay()
{
	Super::BeginPlay();

	Font = LoadObject<UFont>(NULL, TEXT("Font'/Game/FlappyBird/Fonts/SIMYOU_Font.SIMYOU_Font'"));
	Texture = LoadObject<UTexture>(NULL, TEXT("Texture2D'/Game/FlappyBird/Textures/timg.timg'"));
	Mat = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/FlappyBird/Materails/M_HUD.M_HUD'"));

	Pc = GetWorld()->GetFirstPlayerController();
	//开启点击事件响应
	if (Pc)
	{
		Pc->bEnableClickEvents = true;
		Pc->bShowMouseCursor = true;
	}

	//开启输入响应组件
	EnableInput(Pc);

	if (InputComponent)
	{
		InputComponent->BindAction(TEXT("DoJump"), EInputEvent::IE_Pressed,this, &AFBHUD::HUDDoJump);
	}

	//加一下数字贴图
	//Texture2D'/Game/FlappyBird/Textures/Numbers/num_0.num_0'
	for (int32 i=0; i<10; i++)
	{
		UTexture* Num = LoadObject<UTexture>(NULL, *FString::Printf(TEXT("Texture2D'/Game/FlappyBird/Textures/Numbers/num_%d.num_%d'"), i, i));
		Numbers.Add(Num);
	}
}

void AFBHUD::NotifyHitBoxClick(FName BoxName)
{
	if (BoxName == TEXT("Save"))
	{
		//如何进行数据存储
		UFBSaveGame* Save = Cast<UFBSaveGame>(UGameplayStatics::CreateSaveGameObject(UFBSaveGame::StaticClass()));
		Save->SName = TEXT("OKhello");
		Save->Num = 986;
		Save->Array.Add(56);
		Save->Array.Add(123);
		Save->Array.Add(3);
		Save->bRun = true;

		UGameplayStatics::SaveGameToSlot(Save, TEXT("ergou"), 0);

	}
	else if(BoxName == TEXT("Load"))
	{
		//如何进行数据加载
		UFBSaveGame* Load = Cast<UFBSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("ergou"), 0));
		if (Load)
		{
			UE_LOG(LogTemp, Log, TEXT("------------  %s"), *Load->SName);
		}
	}
}

void AFBHUD::NotifyHitBoxRelease(FName BoxName)
{

}

void AFBHUD::DrawFBTest()
{
	//获取屏幕尺寸
	//GetWorld()->GetFirstPlayerController()->GetViewportSize();
	//第二种办法（只能在HUD中使用）
	/*Canvas->ClipX;//获取屏幕宽度
	Canvas->ClipY;//获取屏幕高度
				  / ********************************绘制文字****三种********************************** /
	DrawText(TEXT("你好"), FLinearColor::Green, 50, 50, Font, 5, false);*/

	//直接使用Canvas绘制
	//换颜色

	/*
	{//格式化文本 完成文字拼接
		FString::Printf(TEXT("我今年%d岁"), 10);//结果  我今年10岁

		FText::Format(NSLOCTEXT("FBSP", "K1", "我几年{0}岁"), 10);//结果  我今年10岁
	}*/


	/*Canvas->DrawColor = FColor::Yellow;
	FText text = FText::FromString(TEXT("哈喽"));
	Canvas->DrawText(Font, text, 50, 170);*/

	//第三种 直接使用item
	/*FCanvasTextItem Item(FVector2D(50, 200), text, Font, FLinearColor::Green);
	Canvas->DrawItem(Item);*/

	//在第三种文字绘制方式基础上调整字体大小 Slate必须引入两个模块 "Slate", "SlateCore"
	/*FSlateFontInfo info(Font, 30, TEXT("Default"));
	FCanvasTextItem Item(FVector2D(50, 200), text, info, FLinearColor::Green);
	Canvas->DrawItem(Item);*/

	/******************************绘制贴图************************/
	/*Canvas->DrawColor = FColor::White;
	Canvas->DrawTile(Texture, 200, 100, 400, 400, 0, 0, 423, 417);*/

	//第二种 Item
	//1绘制位置坐标   2绘制贴图资源    3叠加色
	/*FCanvasTileItem TItem(FVector2D(200, 100), Texture->Resource, FLinearColor::White);
	TItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TItem);*/

	/************************绘制材质球*******************************/
	/*FCanvasTileItem tile(FVector2D(100, 50), Mat->GetRenderProxy(0), FVector2D(400, 400), FVector2D(0, 0), FVector2D(1, 1));
	Canvas->DrawItem(tile);*/

	/***********************图形绘制**********************************/
	//绘制线
	/*DrawLine(50, 50, 800, 800, FLinearColor(52, 87, 50), 5);
	//实心矩形
	FCanvasTileItem Rect(FVector2D(50, 50), FVector2D(100, 100), FLinearColor::Yellow);
	Canvas->DrawItem(Rect);
	//绘制空心矩形 也就是线框
	FCanvasBoxItem Box(FVector2D(50, 50), FVector2D(100, 100));
	Box.SetColor(FLinearColor::Green);
	Box.LineThickness = 5;
	Canvas->DrawItem(Box);*/

	if (!Pc)
	{
		return;
	}

	
	if (Pc->WasInputKeyJustPressed(EKeys::LeftMouseButton))
	{
		Pc->GetMousePosition(MouseStartPos.X, MouseStartPos.Y);
		bDrawRect = true;
	}
	if (Pc->WasInputKeyJustReleased(EKeys::LeftMouseButton))
	{
		bDrawRect = false;
	}

	if (bDrawRect)
	{
		FVector2D EndPos;
		Pc->GetMousePosition(EndPos.X, EndPos.Y);//时时获取鼠标的坐标

		FCanvasBoxItem Box(MouseStartPos, EndPos - MouseStartPos);
		Box.SetColor(FLinearColor::Green);
		Box.LineThickness = 5;
		Canvas->DrawItem(Box);
	}

	
	DrawNum(0, 50, 50);


}

void AFBHUD::HUDDoJump()
{
	UE_LOG(LogTemp, Log, TEXT("HUD Jump"));
}

void AFBHUD::DrawNum(int32 Num, int32 X, int32 Y)
{
	if (Num > 999 || Num < 0)//如果你是四位数，我就不给你绘制了，我就绘制个999
	{
		for (int32 i=0; i<3; i++)
		{
			DrawTextureSimple(Numbers[9], X + i * 25, Y);
		}
		return;
	}
	//真正的进行数字绘制

	int32 n1 = Num / 100;
	int32 n2 = Num % 100 / 10;
	int32 n3 = Num % 10;
	DrawTextureSimple(Numbers[n1], X + 25, Y);
	DrawTextureSimple(Numbers[n2], X + 50, Y);
	DrawTextureSimple(Numbers[n3], X + 75, Y);
}
