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
	virtual int GetSize() override;
	virtual TArray<TArray<int>> GetPointArray() override;

	static const int Size = 25;
	inline static const TArray<TArray<int>> PointArray = { {1, 1}, {1, 1} };
};
