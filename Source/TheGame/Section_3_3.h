// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSection.h"
#include "Section_3_3.generated.h"

/**
 * 
 */
UCLASS()
class THEGAME_API ASection_3_3 : public AGameSection
{
	GENERATED_BODY()

public:
	ASection_3_3();
	virtual TileStruct* GetTileInfo() override;

	inline static TileStruct TileInfo { 1.5f, 1.5f, {
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1},
	} };
};
