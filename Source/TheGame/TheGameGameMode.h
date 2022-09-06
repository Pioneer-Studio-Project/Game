// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TheGameGameMode.generated.h"


UCLASS(minimalapi)
class ATheGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATheGameGameMode();
	
	TArray<class AGameSection*> Sections;
	TArray<UClass*> SectionClasses;
	TArray<TArray<bool>> TileMap;
	float TileMapCenter[2];
	int32 MapSize = 0;


protected:
	virtual void BeginPlay();

private:
	void RandomMapCreate(int32);
	void SetTileMApCenter();
	bool AddSection();
	void TestFunction();
	

	UWorld* World;
	FTimerHandle TimerHandle1;

	
};



