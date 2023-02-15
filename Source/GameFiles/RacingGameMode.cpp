// Fill out your copyright notice in the Description page of Project Settings.


#include "RacingGameMode.h"
#include <GameFiles/CheckPoint.h>
#include <GameFiles/BaseVehicle.h>

void ARacingGameMode::RegisterCheckpoint(ACheckPoint* checkpoint)
{
	checkpoints.Add(checkpoint);
}
