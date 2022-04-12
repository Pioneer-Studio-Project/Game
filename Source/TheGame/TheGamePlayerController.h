// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TheGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THEGAME_API ATheGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UGameSettingWidget> SettingWidgetClass;

private:
	void OnSetting();

	UPROPERTY()
	class UGameSettingWidget* SettingWidget;

	FInputModeGameOnly GameInputMode;
	FInputModeUIOnly UIInputMode;
};
