// Fill out your copyright notice in the Description page of Project Settings.


#include "Section_5_5_mainhall.h"

ASection_5_5_mainhall::ASection_5_5_mainhall()
{
	SetStaticMeshByPath(Mesh, TEXT("/Game/Section/Meshes/5_5_mainhall.5_5_mainhall"));
	
}

TileStruct* ASection_5_5_mainhall::GetTileInfo()
{
	return &TileInfo;
}