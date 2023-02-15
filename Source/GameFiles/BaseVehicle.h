// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "BaseVehicle.generated.h"

UCLASS()
class GAMEFILES_API ABaseVehicle : public AWheeledVehicle
{
	GENERATED_BODY()

protected:
	//virtual void BeginPlay() override;

private:
	bool manualGearbox = false;
	int maxGear = 6;
	float checkpointAddition = 25;
	float lastCheckpoint = 0;
	int Laps = 0;

public:

	UPROPERTY(EditAnywhere, Category = "CountdownTimer")
		float timer = 15.f;

	void Lap();

	FTimerHandle TimerHandler;

	UFUNCTION(BlueprintCallable, Category = "COuntdownTimer")
	float GetTimerRemaining();

	UFUNCTION(BlueprintCallable, Category = "COuntdownTimer")
		int GetLaps();

	void CountDownTimer();

	void CheckPointHit();

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Val);

	void MoveRight(float Val);

	void OnHandbrakePressed();

	void OnHandbrakeReleased();

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserHud> PlayerHUDClass;

	UPROPERTY()
		class UUserHUD* PlayerHUD;

};
