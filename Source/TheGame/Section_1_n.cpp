// Fill out your copyright notice in the Description page of Project Settings.


#include "Section_1_n.h"

ASection_1_n::ASection_1_n()
{
	SetStaticMeshByPath(Mesh, TEXT("/Game/Section/Meshes/1_n.1_n"));
}

TileStruct* ASection_1_n::GetTileInfo()
{
	return &TileInfo;
}