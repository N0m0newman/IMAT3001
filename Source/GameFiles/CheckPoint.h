// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CheckPoint.generated.h"

UCLASS()
class GAMEFILES_API ACheckPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
	bool isStart = false;

	void PostInitilizeComponents();

	UFUNCTION()
		void OnVolumeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OverlappingActor, UPrimitiveComponent* OtherComponent, int32 index, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		int32 checkpointIndex;

	UFUNCTION()
		void OnVolumeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OverlappingActor, UPrimitiveComponent* OtherComponent, int32 index);

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CheckpointMesh;

	UPROPERTY(EditAnywhere, Category = "Checkpoint")
		UBoxComponent* VolumeBox;
};
