// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSettingWidget.h"
#include "TheGamePlayerController.h"
#include "kismet/GameplayStatics.h" 
#include "Components/Button.h"
#include "Components/EditableTextBox.h"

void UGameSettingWidget::NativeConstruct()
{
	Super::NativeConstruct();

	btnExit->OnClicked.AddDynamic(this, &UGameSettingWidget::OnExitClicked);
	btnConnect->OnClicked.AddDynamic(this, &UGameSettingWidget::OnConnectClicked);
}

void UGameSettingWidget::OnConnectClicked()
{
	UE_LOG(LogTemp, Log, TEXT("Server IP : %s"), *txtIP->GetText().ToString());
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("WaitingBlock"), true, txtIP->GetText().ToString());
	OnExitClicked();
}

void UGameSettingWidget::OnExitClicked()
{
	auto PlayerController = Cast<ATheGamePlayerController>(GetOwningPlayer());
	if (PlayerController)
	{
		RemoveFromParent();
		PlayerController->SetGameInputMode();
	}
}

