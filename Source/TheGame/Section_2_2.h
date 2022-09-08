// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSection.h"
#include "Section_2_2.generated.h"

/**
 * 
 */
UCLASS()
class THEGAME_API ASection_2_2 : public AGameSection
{
	GENERATED_BODY()

public:
	ASection_2_2();
	virtual TileStruct* GetTileInfo() override;

	inline static TileStruct TileInfo { 1.0f, 1.0f, {
		{1, 1},
		{1, 1}
	} };
};
