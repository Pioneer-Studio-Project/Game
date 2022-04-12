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
	
public:
	ATheGamePlayerController();
	void SetUIInputMode();
	void SetGameInputMode();

protected:
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UGameSettingWidget> SettingWidgetClass;

private:
	void OnSetting();

	UPROPERTY()
	class UUserWidget* CurrentWidget;

	FInputModeGameOnly GameInputMode;
	FInputModeUIOnly UIInputMode;
};
