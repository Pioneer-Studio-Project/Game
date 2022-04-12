// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameSettingWidget.generated.h"

/**
 * 
 */
UCLASS()
class THEGAME_API UGameSettingWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnConnectClicked();

	UFUNCTION()
	void OnExitClicked();

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* txtIP;

	UPROPERTY(meta = (BindWidget))
	class UButton* btnConnect;

	UPROPERTY(meta = (BindWidget))
	class UButton* btnExit;
};
