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

private:
	UPROPERTY()
		class UButton* btnConnect;
};
