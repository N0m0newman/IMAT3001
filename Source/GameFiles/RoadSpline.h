// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "RoadSpline.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEFILES_API ARoadSpline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoadSpline();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(VisibleAnywhere, Category = "Spline")
	USplineComponent* SplineComponent;

	UPROPERTY(EditAnywhere, Category = "Road Mesh")
	UStaticMesh* RoadMesh;
};
