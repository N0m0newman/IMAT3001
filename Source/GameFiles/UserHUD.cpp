// Fill out your copyright notice in the Description page of Project Settings.

#include <Components/TextBlock.h>
#include "BaseVehicle.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "UserHUD.h"

void UUserHUD::NativeConstruct()
{
	Super::NativeConstruct();

}

//A function that is called by blueprint to sync the hud stats with the game stats
void UUserHUD::UpdateHUD(int32 laps, int32 time, int32 speed, int32 gear)
{
	TimerBlock->SetText(FText::AsNumber(time));
	GearTextBlock->SetText(FText::AsNumber(gear));
	SpeedTextBlock->SetText(FText::AsNumber(speed));
	LapCounter->SetText(FText::AsNumber(laps));
}