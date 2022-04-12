// Fill out your copyright notice in the Description page of Project Settings.


#include "TheGamePlayerController.h"
#include "GameSettingWidget.h"

/*
ATheGamePlayerController::ATheGamePlayerController()
{
	int aaaa = 0;
	/*
	static ConstructorHelpers::FClassFinder<UGameSettingWidget> Setting_C(TEXT("/Game/FirstPersonCPP/Blueprints/Setting.Setting_C"));
	if (Setting_C.Succeeded())
	{
		SettingWidgetClass = Setting_C.Class;
	}
	*/
//}


void ATheGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Setting", IE_Pressed, this, &ATheGamePlayerController::OnSetting);
}

void ATheGamePlayerController::OnSetting()
{

}
