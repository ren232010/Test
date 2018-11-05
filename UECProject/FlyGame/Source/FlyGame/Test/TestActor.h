// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StreamableManager.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"



USTRUCT(BlueprintType)
struct FDataStruct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere)
	FString Name;
	UPROPERTY(EditAnywhere)
	int32 Age;
	UPROPERTY(EditAnywhere)
	bool bReady;
};

UCLASS()
class FLYGAME_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CallBackData();

protected:
	class APlayerController* m_PC;
	UPROPERTY()
	AActor* m_Actor;
	UPROPERTY()
	AActor* m_ActorN;
	UPROPERTY()
	TArray<AActor*> Array;

	void SetActorN(AActor* actor);
	//ֱ����������
	UPROPERTY(EditAnywhere)
	class USoundBase* Sound;
	UPROPERTY(EditAnywhere)
	FStringAssetReference SoundRef;



	//���Խ���Լ���ļ���������ü��أ������ʲ���
	UPROPERTY(EditAnywhere)
	TAssetPtr<USoundBase> TASound;//ʰȡ�����ʲ�
	UPROPERTY(EditAnywhere)
	TAssetSubclassOf<class ACBgActor> Bg;//ʰȡ��ģ���ʲ�
	UPROPERTY(EditAnywhere)
	class UDataTable* Data;

	//�ʲ�������
	FStreamableManager AssetMgr;


};
