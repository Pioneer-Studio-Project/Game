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
	virtual int GetSize() override;
	virtual TArray<TArray<int>> GetPointArray() override;

	static const int Size = 1;
	inline static const TArray<TArray<int>> PointArray = { {1, 1}, {1, 1} };
};
