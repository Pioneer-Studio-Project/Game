// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameSection.generated.h"


class THEGAME_API TileStruct
{
public:
	TileStruct(float, float, TArray<TArray<int>>);
	int GetSize();

	float center_x;
	float center_y;
	TArray<TArray<int>> value;
};

UCLASS()
class THEGAME_API AGameSection : public AActor
{
	GENERATED_BODY()
	
public:	 
	AGameSection();

	virtual TileStruct* GetTileInfo() {	return nullptr;	};

	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;

protected:
	void SetStaticMeshByPath(UStaticMeshComponent* Mesh, FString AssetPath);


private:
	



};
