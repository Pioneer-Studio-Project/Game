// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSection.h"
#include "Section_5_5_mainhall.generated.h"

/**
 * 
 */
UCLASS()
class THEGAME_API ASection_5_5_mainhall : public AGameSection
{
	GENERATED_BODY()

public:
	ASection_5_5_mainhall();
	virtual TileStruct* GetTileInfo() override;

	inline static TileStruct TileInfo { 2.5f, 2.5f, {
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
	} };
};
