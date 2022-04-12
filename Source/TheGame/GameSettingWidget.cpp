// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSettingWidget.h"
#include "Components/Button.h"

void UGameSettingWidget::NativeConstruct()
{
	Super::NativeConstruct();

	btnConnect = Cast<UButton>(GetWidgetFromName(TEXT("btnConnect")));
	if (btnConnect)
	{
		btnConnect->OnClicked.AddDynamic(this, &UGameSettingWidget::OnConnectClicked);
	}
}

void UGameSettingWidget::OnConnectClicked()
{
	//IP
}