// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <GameFiles/CheckPoint.h>
#include "GameFramework/GameModeBase.h"
#include "RacingGameMode.generated.h"

UCLASS()
class GAMEFILES_API ARacingGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	TArray<ACheckPoint*> checkpoints;

	void RegisterCheckpoint(ACheckPoint* checkpoint);

};
