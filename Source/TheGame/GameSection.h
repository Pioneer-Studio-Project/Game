// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameSection.generated.h"

UCLASS()
class THEGAME_API AGameSection : public AActor
{
	GENERATED_BODY()
	
public:	 
	AGameSection();

	virtual int GetSize() { return 0; };
	virtual TArray<TArray<int>> GetPointArray() { TArray<TArray<int>> temp; return temp; };

	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;

protected:
	void SetStaticMeshByPath(UStaticMeshComponent* Mesh, FString AssetPath);


private:
	



};
