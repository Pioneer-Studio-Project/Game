// Fill out your copyright notice in the Description page of Project Settings.


#include "TheGamePlayerController.h"
#include "GameFramework/Character.h"
#include "GameSettingWidget.h"
#include "kismet/GameplayStatics.h"

ATheGamePlayerController::ATheGamePlayerController()
{
	static ConstructorHelpers::FClassFinder<UGameSettingWidget> Setting_C(TEXT("/Game/Assets/FirstPersonCPP/Blueprints/Setting"));
	if (Setting_C.Succeeded())
	{
		SettingWidgetClass = Setting_C.Class;
	}
}

void ATheGamePlayerController::BeginPlay()
{
	MyPawn = GetPawn();
	MyCharacter = Cast<ACharacter>(MyPawn);
}


void ATheGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Bind setting events
	InputComponent->BindAction("Setting", IE_Pressed, this, &ATheGamePlayerController::OnSetting);

	// Bind jump events
	InputComponent->BindAction("Jump", IE_Pressed, this, &ATheGamePlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ATheGamePlayerController::StopJumping);

	// Bind movement 
	InputComponent->BindAxis("MoveForward", this, &ATheGamePlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATheGamePlayerController::MoveRight);

	// Bind rotation events
	InputComponent->BindAxis("Turn", this, &ATheGamePlayerController::Turn);
	InputComponent->BindAxis("LookUp", this, &ATheGamePlayerController::LookUp);

	//Bind special events
	InputComponent->BindAction("Special", IE_Pressed, this, &ATheGamePlayerController::Special);
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

void ATheGamePlayerController::Jump()
{
	if (MyCharacter)
	{
		MyCharacter->Jump();
	}
}

void ATheGamePlayerController::StopJumping()
{
	if (MyCharacter)
	{
		MyCharacter->StopJumping();
	}
}

void ATheGamePlayerController::MoveForward(float Value)
{
	if (MyPawn && Value != 0.0f)
	{
		// add movement in that direction
		MyPawn->AddMovementInput(MyPawn->GetActorForwardVector(), Value);
	}
}

void ATheGamePlayerController::MoveRight(float Value)
{
	if (MyPawn && Value != 0.0f)
	{
		// add movement in that direction
		MyPawn->AddMovementInput(MyPawn->GetActorRightVector(), Value);
	}
}

void ATheGamePlayerController::Turn(float Value)
{
	if (MyPawn && Value != 0.0f)
	{
		MyPawn->AddControllerYawInput(Value);
	}
}

void ATheGamePlayerController::LookUp(float Value)
{
	if (MyPawn && Value != 0.0f)
	{
 		MyPawn->AddControllerPitchInput(Value);
	}
}

void ATheGamePlayerController::Special()
{
	
}