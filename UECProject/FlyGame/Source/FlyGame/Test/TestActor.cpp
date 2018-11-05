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
		////构建一个文本Json文档  解析名称值格式JSON
		//FString JData(TEXT("{\"name\":\"ergou\"}"));
		//TSharedRef<TJsonReader<TCHAR>> Reader =  TJsonReaderFactory<TCHAR>::Create(JData);//构建Json解析器

		//TSharedPtr<FJsonObject> JsonParser;//Json外层对象所引
		////使用解析器进行反序列化解析
		//if (FJsonSerializer::Deserialize(Reader, JsonParser))//从Reader当中，反序列化到JsonParser(这是一个内存对象结构)中
		//{
		//	FString Value = JsonParser->GetStringField(TEXT("name"));//获取当前Json对象的名称的值
		//	UE_LOG(LogTemp, Log, TEXT("%s"), *Value);
		//}

		//解析有序列表
		/*FString JData(TEXT("[{\"name\":\"ergou\"}]"));
		TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(JData);//构建Json的数据Reader

		TArray<TSharedPtr<FJsonValue>> JsonParser;
		if (FJsonSerializer::Deserialize(Reader, JsonParser))
		{
			FString Value = JsonParser[0]->AsObject()->GetStringField("name");
			UE_LOG(LogTemp, Log, TEXT("%s"), *Value);
		}*/

		//文件解析的方式进行解析Json
		/*FString Path = FPaths::ProjectSavedDir() / "1.json";//构建数据路径
		//校验数据类型是否有效
		if (FPaths::FileExists(Path))
		{
			FString JData;
			FFileHelper::LoadFileToString(JData, *Path);//读取磁盘内容，将内容转成文本形式
			
			TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(JData);//构建Json解析器

			TSharedPtr<FJsonObject> RootObj;
			if (FJsonSerializer::Deserialize(Reader, RootObj))
			{
				//先拿到person数组
				TArray<TSharedPtr<FJsonValue>> PArray = RootObj->GetArrayField(TEXT("person"));
				TSharedPtr<FJsonObject> One = PArray[0]->AsObject();
				//拿到teachers数组
				TArray<TSharedPtr<FJsonValue>> TeArray = One->GetArrayField(TEXT("teachers"));
				TSharedPtr<FJsonObject> zhang = TeArray[0]->AsObject()->GetObjectField(TEXT("zhang"));
				FString Name = zhang->GetArrayField(TEXT("hobby"))[0]->AsString();

				UE_LOG(LogTemp, Log, TEXT("%s"), *Name);


				//int32 Num = RootObj->GetArrayField(TEXT("person"))[0]->AsObject()->GetArrayField(TEXT("teachers")).Num();
				//UE_LOG(LogTemp, Log, TEXT("%d"), Num);
			}*/
		//}
		//写Json数据 名称值
		/*TSharedPtr<FJsonObject> Root(new FJsonObject());//构建json对象
		Root->SetStringField(TEXT("name"), TEXT("ok"));//设置对象值内容
		Root->SetBoolField(TEXT("Work"), true);
		Root->SetNumberField(TEXT("Age"), 50);

		FString JData;
		//构建jsonWriter
		TSharedRef<TJsonWriter<TCHAR>> Writer = TJsonWriterFactory<TCHAR>::Create(&JData);
		if (FJsonSerializer::Serialize(Root.ToSharedRef(), Writer))//将json对象序列化到write中，write会将数据写入到string中
		{
			UE_LOG(LogTemp, Log, TEXT("%s"), *JData);
		}*/

		//序列化对象 有序列表
		/*TArray<TSharedPtr<FJsonValue>> Array;

		TSharedPtr<FJsonObject> Obj(new FJsonObject());//构建一个数组中的对象
		Obj->SetStringField(TEXT("name"), TEXT("ok"));//设置对象值内容
		Obj->SetBoolField(TEXT("Work"), true);
		Obj->SetNumberField(TEXT("Age"), 50);

		TSharedPtr<FJsonValueObject> D1(new FJsonValueObject(Obj));//构建成了一个Value，并且是Object类型的Value

		Array.Add(D1);//数据进行了装填
		//序列化对象结构
		FString JData;
		TSharedRef<TJsonWriter<TCHAR>> Writer = TJsonWriterFactory<TCHAR>::Create(&JData);

		if (FJsonSerializer::Serialize(Array, Writer))
		{
			//向磁盘写入数据
			FString Path = FPaths::ProjectSavedDir() / TEXT("2.json");
			FFileHelper::SaveStringToFile(JData, *Path);
		}*/

		TSharedPtr<FJsonObject> Root(new FJsonObject());
		TArray<TSharedPtr<FJsonValue>> Array;
		TSharedPtr<FJsonObject> Item_0(new FJsonObject());
		
		{
			TArray<TSharedPtr<FJsonValue>> TeArray;
			TSharedPtr<FJsonObject> techer(new FJsonObject());

			//数据根
			TSharedPtr<FJsonObject> Zq(new FJsonObject());
			Zq->SetStringField(TEXT("name"), TEXT("zq"));
			techer->SetObjectField(TEXT("zhang"), Zq);

			TSharedPtr<FJsonValueObject> t1(new FJsonValueObject(techer));
			TeArray.Add(t1);

			Item_0->SetArrayField(TEXT("Name"), TeArray);
		}


		TSharedPtr<FJsonValueObject> D1(new FJsonValueObject(Item_0));

		//加OK
		TSharedPtr<FJsonValueString> D2(new FJsonValueString(TEXT("nihao")));

		Array.Add(D1);
		Array.Add(D2);

		Root->SetArrayField(TEXT("person"), Array);

		//序列化对象结构
		FString JData;
		TSharedRef<TJsonWriter<TCHAR>> Writer = TJsonWriterFactory<TCHAR>::Create(&JData);

		if (FJsonSerializer::Serialize(Root.ToSharedRef(), Writer))
		{
			//向磁盘写入数据
			FString Path = FPaths::ProjectSavedDir() / TEXT("2.json");
			FFileHelper::SaveStringToFile(JData, *Path);
		}

	}

	if (m_PC->WasInputKeyJustPressed(EKeys::W))
	{
		USoundBase* Sound = Cast<USoundBase>(TASound.Get());//将加载成功的资产尝试进行类型转换
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

