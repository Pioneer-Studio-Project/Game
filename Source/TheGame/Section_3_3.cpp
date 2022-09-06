// Fill out your copyright notice in the Description page of Project Settings.


#include "Section_3_3.h"

ASection_3_3::ASection_3_3()
{
	SetStaticMeshByPath(Mesh, TEXT("/Game/Section/Meshes/3_3.3_3"));
}

int ASection_3_3::GetSize()
{
	return Size;
}

TArray<TArray<int>> ASection_3_3::GetPointArray()
{
	return PointArray;
}