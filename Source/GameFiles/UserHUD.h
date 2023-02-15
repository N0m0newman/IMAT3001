// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <GameFiles/BaseVehicle.h>
#include "UserHUD.generated.h"

/**
 * 
 */
UCLASS()
class GAMEFILES_API UUserHUD : public UUserWidget
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable, Category = "UpdateHUD")
	void UpdateHUD(int32 laps, int32 time, int32 speed, int32 gear);

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* TimerBlock;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* GearTextBlock;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* SpeedTextBlock;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* LapCounter;

protected:

	void NativeConstruct() override;
};
