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
	virtual void BeginPlay();
	APawn* MyPawn;
	ACharacter* MyCharacter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UGameSettingWidget> SettingWidgetClass;

private:
	void OnSetting();
	void Jump();
	void StopJumping();
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void Special();

	
	class UUserWidget* CurrentWidget;

	FInputModeGameOnly GameInputMode;
	FInputModeUIOnly UIInputMode;
};
