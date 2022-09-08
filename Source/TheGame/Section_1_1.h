// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSection.h"
#include "Section_1_1.generated.h"

/**
 * 
 */
UCLASS()
class THEGAME_API ASection_1_1 : public AGameSection
{
	GENERATED_BODY()

public:
	ASection_1_1();
	virtual TileStruct* GetTileInfo() override;

	inline static TileStruct TileInfo { 0.5f, 0.5f, {
		{1}
	} };
};
