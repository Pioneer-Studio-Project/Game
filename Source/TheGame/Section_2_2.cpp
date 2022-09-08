// Fill out your copyright notice in the Description page of Project Settings.


#include "Section_2_2.h"

ASection_2_2::ASection_2_2()
{
	SetStaticMeshByPath(Mesh, TEXT("/Game/Section/Meshes/2_2.2_2"));
}

TileStruct* ASection_2_2::GetTileInfo()
{
	return &TileInfo;
}