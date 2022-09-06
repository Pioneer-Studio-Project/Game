// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSection.h"

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
