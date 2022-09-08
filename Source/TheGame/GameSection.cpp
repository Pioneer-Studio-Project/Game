// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSection.h"

TileStruct::TileStruct(float x = 0.5f, float y = 0.5f, TArray<TArray<int>> v = { {1} })
{
	center_x = x;
	center_y = y;
	value = v;
}

int TileStruct::GetSize()
{
	int num = 0;
	for (int i = 0; i < value.Num(); i++)
	{
		for (int j = 0; j < value[i].Num(); j++)
		{
			if (value[i][j] != 0)
			{
				num++;
			}
		}
	}
	return num;
}

AGameSection::AGameSection()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;
}

void AGameSection::SetStaticMeshByPath(UStaticMeshComponent* Component, FString AssetPath)
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> obj(*AssetPath);
	if (obj.Succeeded())
	{
		Component->SetStaticMesh(obj.Object);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Failed to load staticmesh asset. : %s"), *AssetPath);
	}
}