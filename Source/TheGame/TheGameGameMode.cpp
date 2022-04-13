// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheGameGameMode.h"
#include "TheGameHUD.h"
#include "TheGameCharacter.h"
#include "TheGamePlayerController.h"
#include "UObject/ConstructorHelpers.h"

ATheGameGameMode::ATheGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATheGameHUD::StaticClass();

	// set
	PlayerControllerClass = ATheGamePlayerController::StaticClass();
}
