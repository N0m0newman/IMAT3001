// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseVehicle.h"
#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "Kismet/GameplayStatics.h"
#include "UserHUD.h"
#include "Blueprint/UserWidget.h"

void ABaseVehicle::Lap()
{
	//Add to laps counter
	Laps++;
	//Make game harder by decreasing the amount added for each checkpoint
	checkpointAddition--;
}

//Getter for remaining timer for UI sync
float ABaseVehicle::GetTimerRemaining()
{
	return timer;
}

//getter for laps UI Sync
int ABaseVehicle::GetLaps()
{
	return Laps;
}

//Called every second.
void ABaseVehicle::CountDownTimer()
{
	timer--;
	//check if the timer ended if so clear the timer and quit the game
	if (timer < 1) {
		//timer ended game over.
		GetWorldTimerManager().ClearTimer(TimerHandler);
		UGameplayStatics::OpenLevel(this, TEXT("MainMenu"));
	}
}

//When the player passes through a checkpoint add time to the countdown
void ABaseVehicle::CheckPointHit()
{
	timer += checkpointAddition;
}

//Begin Play Function
void ABaseVehicle::BeginPlay()
{
	Super::BeginPlay();

	//Create the countdown timer the player is trying to beat
	GetWorldTimerManager().SetTimer(TimerHandler, this, &ABaseVehicle::CountDownTimer, 1.f, true);
}

//Control Binding aswell as Vehicle COmponent Setting Bindings
void ABaseVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//bind basic key controls
	PlayerInputComponent->BindAxis("Throttle", this, &ABaseVehicle::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseVehicle::MoveRight);
	PlayerInputComponent->BindAction("Handbrake", IE_Pressed, this, &ABaseVehicle::OnHandbrakePressed);
	PlayerInputComponent->BindAction("Handbrake", IE_Released, this, &ABaseVehicle::OnHandbrakeReleased);
	GetVehicleMovementComponent()->SetAutoActivate(true);
	GetVehicleMovementComponent()->SetUseAutoGears(true);
	GetVehicleMovementComponent()->bReverseAsBrake = true;
}

//Acceleration and Braking Function
void ABaseVehicle::MoveForward(float Val)
{
	GetVehicleMovementComponent()->SetThrottleInput(Val);
}


//Steering Functions
void ABaseVehicle::MoveRight(float Val)
{
	GetVehicleMovementComponent()->SetSteeringInput(Val);
}


//HandBrake Functions
void ABaseVehicle::OnHandbrakePressed()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void ABaseVehicle::OnHandbrakeReleased()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}
