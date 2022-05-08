// Fill out your copyright notice in the Description page of Project Settings.


#include "TheGamePlayerController.h"
#include "GameSettingWidget.h"

ATheGamePlayerController::ATheGamePlayerController()
{
	static ConstructorHelpers::FClassFinder<UGameSettingWidget> Setting_C(TEXT("/Game/FirstPersonCPP/Blueprints/Setting"));
	if (Setting_C.Succeeded())
	{
		SettingWidgetClass = Setting_C.Class;
	}
}


void ATheGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Setting", IE_Pressed, this, &ATheGamePlayerController::OnSetting);
}

void ATheGamePlayerController::OnSetting()
{
	CurrentWidget = CreateWidget<UGameSettingWidget>(this, SettingWidgetClass);
	if (CurrentWidget)
	{
		CurrentWidget->AddToViewport(3);
		SetUIInputMode();
	}
}

void ATheGamePlayerController::SetUIInputMode()
{
	SetInputMode(UIInputMode);
	bShowMouseCursor = true;
}

void ATheGamePlayerController::SetGameInputMode()
{
	SetInputMode(GameInputMode);
	bShowMouseCursor = false;
}