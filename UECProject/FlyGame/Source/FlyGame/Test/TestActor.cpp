// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "FBTBase.h"
#include "Kismet/GameplayStatics.h"
#include "CBgActor.h"
#include "Engine/DataTable.h"
#include "JsonReader.h"
#include "JsonObject.h"
#include "JsonSerializer.h"
#include "Paths.h"
#include "FileHelper.h"






// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SoundRef.SetPath(TEXT("SoundWave'/Game/FlyGame/Sounds/coin.coin'"));

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
	m_PC = GetWorld()->GetFirstPlayerController();
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!m_PC)
	{
		return;
	}

	if (m_PC->WasInputKeyJustPressed(EKeys::Q))
	{
		////����һ���ı�Json�ĵ�  ��������ֵ��ʽJSON
		//FString JData(TEXT("{\"name\":\"ergou\"}"));
		//TSharedRef<TJsonReader<TCHAR>> Reader =  TJsonReaderFactory<TCHAR>::Create(JData);//����Json������

		//TSharedPtr<FJsonObject> JsonParser;//Json����������
		////ʹ�ý��������з����л�����
		//if (FJsonSerializer::Deserialize(Reader, JsonParser))//��Reader���У������л���JsonParser(����һ���ڴ����ṹ)��
		//{
		//	FString Value = JsonParser->GetStringField(TEXT("name"));//��ȡ��ǰJson��������Ƶ�ֵ
		//	UE_LOG(LogTemp, Log, TEXT("%s"), *Value);
		//}

		//���������б�
		/*FString JData(TEXT("[{\"name\":\"ergou\"}]"));
		TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(JData);//����Json������Reader

		TArray<TSharedPtr<FJsonValue>> JsonParser;
		if (FJsonSerializer::Deserialize(Reader, JsonParser))
		{
			FString Value = JsonParser[0]->AsObject()->GetStringField("name");
			UE_LOG(LogTemp, Log, TEXT("%s"), *Value);
		}*/

		//�ļ������ķ�ʽ���н���Json
		/*FString Path = FPaths::ProjectSavedDir() / "1.json";//��������·��
		//У�����������Ƿ���Ч
		if (FPaths::FileExists(Path))
		{
			FString JData;
			FFileHelper::LoadFileToString(JData, *Path);//��ȡ�������ݣ�������ת���ı���ʽ
			
			TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(JData);//����Json������

			TSharedPtr<FJsonObject> RootObj;
			if (FJsonSerializer::Deserialize(Reader, RootObj))
			{
				//���õ�person����
				TArray<TSharedPtr<FJsonValue>> PArray = RootObj->GetArrayField(TEXT("person"));
				TSharedPtr<FJsonObject> One = PArray[0]->AsObject();
				//�õ�teachers����
				TArray<TSharedPtr<FJsonValue>> TeArray = One->GetArrayField(TEXT("teachers"));
				TSharedPtr<FJsonObject> zhang = TeArray[0]->AsObject()->GetObjectField(TEXT("zhang"));
				FString Name = zhang->GetArrayField(TEXT("hobby"))[0]->AsString();

				UE_LOG(LogTemp, Log, TEXT("%s"), *Name);


				//int32 Num = RootObj->GetArrayField(TEXT("person"))[0]->AsObject()->GetArrayField(TEXT("teachers")).Num();
				//UE_LOG(LogTemp, Log, TEXT("%d"), Num);
			}*/
		//}
		//дJson���� ����ֵ
		/*TSharedPtr<FJsonObject> Root(new FJsonObject());//����json����
		Root->SetStringField(TEXT("name"), TEXT("ok"));//���ö���ֵ����
		Root->SetBoolField(TEXT("Work"), true);
		Root->SetNumberField(TEXT("Age"), 50);

		FString JData;
		//����jsonWriter
		TSharedRef<TJsonWriter<TCHAR>> Writer = TJsonWriterFactory<TCHAR>::Create(&JData);
		if (FJsonSerializer::Serialize(Root.ToSharedRef(), Writer))//��json�������л���write�У�write�Ὣ����д�뵽string��
		{
			UE_LOG(LogTemp, Log, TEXT("%s"), *JData);
		}*/

		//���л����� �����б�
		/*TArray<TSharedPtr<FJsonValue>> Array;

		TSharedPtr<FJsonObject> Obj(new FJsonObject());//����һ�������еĶ���
		Obj->SetStringField(TEXT("name"), TEXT("ok"));//���ö���ֵ����
		Obj->SetBoolField(TEXT("Work"), true);
		Obj->SetNumberField(TEXT("Age"), 50);

		TSharedPtr<FJsonValueObject> D1(new FJsonValueObject(Obj));//��������һ��Value��������Object���͵�Value

		Array.Add(D1);//���ݽ�����װ��
		//���л�����ṹ
		FString JData;
		TSharedRef<TJsonWriter<TCHAR>> Writer = TJsonWriterFactory<TCHAR>::Create(&JData);

		if (FJsonSerializer::Serialize(Array, Writer))
		{
			//�����д������
			FString Path = FPaths::ProjectSavedDir() / TEXT("2.json");
			FFileHelper::SaveStringToFile(JData, *Path);
		}*/

		TSharedPtr<FJsonObject> Root(new FJsonObject());
		TArray<TSharedPtr<FJsonValue>> Array;
		TSharedPtr<FJsonObject> Item_0(new FJsonObject());
		
		{
			TArray<TSharedPtr<FJsonValue>> TeArray;
			TSharedPtr<FJsonObject> techer(new FJsonObject());

			//���ݸ�
			TSharedPtr<FJsonObject> Zq(new FJsonObject());
			Zq->SetStringField(TEXT("name"), TEXT("zq"));
			techer->SetObjectField(TEXT("zhang"), Zq);

			TSharedPtr<FJsonValueObject> t1(new FJsonValueObject(techer));
			TeArray.Add(t1);

			Item_0->SetArrayField(TEXT("Name"), TeArray);
		}


		TSharedPtr<FJsonValueObject> D1(new FJsonValueObject(Item_0));

		//��OK
		TSharedPtr<FJsonValueString> D2(new FJsonValueString(TEXT("nihao")));

		Array.Add(D1);
		Array.Add(D2);

		Root->SetArrayField(TEXT("person"), Array);

		//���л�����ṹ
		FString JData;
		TSharedRef<TJsonWriter<TCHAR>> Writer = TJsonWriterFactory<TCHAR>::Create(&JData);

		if (FJsonSerializer::Serialize(Root.ToSharedRef(), Writer))
		{
			//�����д������
			FString Path = FPaths::ProjectSavedDir() / TEXT("2.json");
			FFileHelper::SaveStringToFile(JData, *Path);
		}

	}

	if (m_PC->WasInputKeyJustPressed(EKeys::W))
	{
		USoundBase* Sound = Cast<USoundBase>(TASound.Get());//�����سɹ����ʲ����Խ�������ת��
		if (Sound)
		{
			UGameplayStatics::PlaySound2D(this, Sound);
		}
	}

	if (m_PC->WasInputKeyJustPressed(EKeys::E))
	{

	}
}

void ATestActor::CallBackData()
{
	UE_LOG(LogTemp, Log, TEXT("load is success"));
}

void ATestActor::SetActorN(AActor* actor)
{
	m_ActorN = actor;
}

