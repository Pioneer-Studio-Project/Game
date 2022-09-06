// Fill out your copyright notice in the Description page of Project Settings.


#include "Section_1_1.h"

ASection_1_1::ASection_1_1()
{
	SetStaticMeshByPath(Mesh, TEXT("/Game/Section/Meshes/1_1.1_1"));
}

int ASection_1_1::GetSize()
{
	return Size;
}

TArray<TArray<int>> ASection_1_1::GetPointArray()
{
	return PointArray;
}