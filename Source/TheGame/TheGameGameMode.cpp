// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheGameGameMode.h"
#include "TheGameHUD.h"
#include "TheGameCharacter.h"
#include "TheGamePlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerManager.h"
#include "TheGameGameState.h"
#include "GameSection.h"
#include "Section_5_5_mainhall.h"
#include <random>

ATheGameGameMode::ATheGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Assets/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// set class
	HUDClass = ATheGameHUD::StaticClass();
	PlayerControllerClass = ATheGamePlayerController::StaticClass();
	GameStateClass = ATheGameGameState::StaticClass(); //GetGameState<ATheGameGameState>();

	// set field
	for (TObjectIterator<UClass> It; It; ++It)
	{
		if (It->IsChildOf(AGameSection::StaticClass()) && !It->HasAnyClassFlags(CLASS_Abstract))
		{
			SectionClasses.Add(*It);
		}
	}
	SectionClasses.Remove(AGameSection::StaticClass());
}

void ATheGameGameMode::BeginPlay()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle1, this, &ATheGameGameMode::TestFunction, 1.0f, true);
}

void ATheGameGameMode::TestFunction()
{
	RandomMapCreate(100);
	GetWorldTimerManager().ClearTimer(TimerHandle1);
}

void ATheGameGameMode::RandomMapCreate(int32 MaxSize)
{
	World = GetWorld();
	
	if (MapSize == 0)
	{
		TArray<bool> arr;
		arr.Init(false, 30);
		TileMap.Init(arr, 30);
		SetTileMApCenter();

		UClass* cls = ASection_5_5_mainhall::StaticClass();
		auto CDO = cls->GetDefaultObject<AGameSection>();

		
		FVector location = FVector(0.0f, 0.0f, 0.0f);
		FRotator rotation = FRotator(0.0f, 0.0f, 0.0f);

		//�� ��ġ���� ����� ���� Ÿ�ϵ鿡 ��� �Ҵ�
		//TileMapCenter[0] + 

		MapSize += CDO->GetSize();
		Sections.Add(World->SpawnActor<AGameSection>(cls, location, rotation));
	}
	
	while (MapSize < 0)
	{
		if (!AddSection())
		{
			UE_LOG(LogTemp, Error, TEXT("AddSection Fail"));
			break;
		}
	}
}

void ATheGameGameMode::SetTileMApCenter()
{
	TileMapCenter[0] = (float)(1 + TileMap.Num()) / 2.0f;
	TileMapCenter[1] = (float)(1 + TileMap[0].Num()) / 2.0f;
}

bool ATheGameGameMode::AddSection()
{
	
	TArray<UClass*> TheClasses;
	UClass* cls = nullptr;
	AGameSection* CDO = nullptr;
	FVector location;
	FRotator rotation = FRotator(0.0f, 0.0f, 0.0f);

	//Ÿ�� ���� ����Ʈ �ʱ�ȭ
	while (1 != 0) //Ÿ�� ���� ����Ʈ ũ�� != 0
	{
		//Ÿ�� ���� ����Ʈ���� ������ ����
		//Ÿ�� ���� ����Ʈ���� �� Ÿ�� ����
		TheClasses = SectionClasses;
		while (TheClasses.Num() != 0)
		{
			cls = TheClasses[FMath::RandRange(0, TheClasses.Num() - 1)];
			CDO = cls->GetDefaultObject<AGameSection>();
			TheClasses.Remove(cls);
		FOR1:
			for (;;) //������ ���� ��ġ�� �� �ϳ�
			{
			FOR2:
				for (;;) //�� ��ġ���� ����� ���� Ÿ�ϵ� �� �ϳ�
				{
					if (1) //�� Ÿ���� ����
					{
						TArray<bool> arr;
						arr.Init(false, TileMap.Num()+2);
						TileMap.Insert(arr, 0);
						for (int i = 0; i < TileMap.Num(); i++)
						{
							TileMap[i].Insert(false, 0);
							TileMap[i].Add(false);
						}
						TileMap.Add(arr);
						SetTileMApCenter();
						goto FOR2;
					}
					if (1) //�� Ÿ�Ͽ� �̹� ��� ����
					{
						goto FOR1;
					}
				}
				//�� ��ġ���� ����� ���� Ÿ�ϵ鿡 ��� �Ҵ�
				MapSize += CDO->GetSize();
				Sections.Add(World->SpawnActor<AGameSection>(cls, location, rotation));
				return true;
			}
		}
	}
	return false;
}

