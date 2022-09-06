// Fill out your copyright notice in the Description page of Project Settings.


#include "Section_1_n.h"

ASection_1_n::ASection_1_n()
{
	SetStaticMeshByPath(Mesh, TEXT("/Game/Section/Meshes/1_n.1_n"));
}

int ASection_1_n::GetSize()
{
	return Size;
}

TArray<TArray<int>> ASection_1_n::GetPointArray()
{
	return PointArray;
}