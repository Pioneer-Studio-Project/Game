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

		//그 위치에서 블록이 놓일 타일들에 블록 할당
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

	//타일 선택 리스트 초기화
	while (1 != 0) //타일 선택 리스트 크기 != 0
	{
		//타일 선택 리스트에서 무작위 선택
		//타일 선택 리스트에서 그 타일 제거
		TheClasses = SectionClasses;
		while (TheClasses.Num() != 0)
		{
			cls = TheClasses[FMath::RandRange(0, TheClasses.Num() - 1)];
			CDO = cls->GetDefaultObject<AGameSection>();
			TheClasses.Remove(cls);
		FOR1:
			for (;;) //가능한 인접 위치들 중 하나
			{
			FOR2:
				for (;;) //그 위치에서 블록이 놓일 타일들 중 하나
				{
					if (1) //그 타일이 없음
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
					if (1) //그 타일에 이미 블록 있음
					{
						goto FOR1;
					}
				}
				//그 위치에서 블록이 놓일 타일들에 블록 할당
				MapSize += CDO->GetSize();
				Sections.Add(World->SpawnActor<AGameSection>(cls, location, rotation));
				return true;
			}
		}
	}
	return false;
}

