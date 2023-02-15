// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SplineComponent.h"
#include "RoadSpline.h"
#include "Components/SplineMeshComponent.h"

// Sets default values
ARoadSpline::ARoadSpline()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//create subobject that is seen in blueprint as component
	SplineComponent = CreateDefaultSubobject<USplineComponent>("Spline");
	if (SplineComponent) {
		SetRootComponent(SplineComponent);
	}
}

// Called when the game starts or when spawned
void ARoadSpline::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARoadSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Called at construction
void ARoadSpline::OnConstruction(const FTransform& Transform)
{
	//run base
	Super::OnConstruction(Transform);
	//null check of spline comp
	if (SplineComponent) {

		int Splines = SplineComponent->GetNumberOfSplinePoints();
		//loop through all spline points - start
		for (int i = 0; i < (Splines - 1); i++)
		{
			//create a new spline mesh object
			USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this, USplineMeshComponent::StaticClass());
			//bind the static mesh set in blueprint to it
			SplineMesh->SetStaticMesh(RoadMesh);
			//register the mesh with the world and setup creation methods and mobility
			SplineMesh->RegisterComponentWithWorld(GetWorld());
			SplineMesh->CreationMethod = EComponentCreationMethod::UserConstructionScript;
			SplineMesh->SetMobility(EComponentMobility::Movable);
			//finally attach it to the spline path
			SplineMesh->AttachToComponent(SplineComponent, FAttachmentTransformRules::KeepRelativeTransform);

			//map start and end tangent points
			const FVector StartPoint = SplineComponent->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::Type::Local);
			const FVector StartTangent = SplineComponent->GetTangentAtSplinePoint(i, ESplineCoordinateSpace::Type::Local);
			const FVector EndPoint = SplineComponent->GetLocationAtSplinePoint(i + 1, ESplineCoordinateSpace::Type::Local);
			const FVector EndTanget = SplineComponent->GetTangentAtSplinePoint(i + 1, ESplineCoordinateSpace::Type::Local);
			SplineMesh->SetStartAndEnd(StartPoint, StartTangent, EndPoint, EndTanget, true);

			//set the collision
			SplineMesh->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
		}
	}
}

