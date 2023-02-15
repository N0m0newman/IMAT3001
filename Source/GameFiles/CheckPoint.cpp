
#include "CheckPoint.h"
#include "Components/StaticMeshComponent.h"
#include <GameFiles/BaseVehicle.h>
#include <GameFiles/RacingGameMode.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ACheckPoint::ACheckPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Static mesh for the checkpoint
	
	CheckpointMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Checkpoint Mesh"));
	CheckpointMesh->AttachTo(RootComponent, TEXT("AWAWAW"), EAttachLocation::SnapToTargetIncludingScale, false);

	//Create a trigger volume & assign collision response
	VolumeBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	VolumeBox->InitBoxExtent(FVector(100.f, 630.f, 600));
	VolumeBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	SetRootComponent(VolumeBox);

	//Setup Volume Events
	VolumeBox->OnComponentBeginOverlap.AddDynamic(this, &ACheckPoint::OnVolumeBeginOverlap);
	VolumeBox->OnComponentEndOverlap.AddDynamic(this, &ACheckPoint::OnVolumeEndOverlap);
}

// Called when the game starts or when spawned
void ACheckPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACheckPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckPoint::PostInitilizeComponents()
{
	Super::PostInitializeComponents();

}

void ACheckPoint::OnVolumeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OverlappingActor, UPrimitiveComponent* OtherComponent, int32 index, bool bFromSweep, const FHitResult& SweepResult)
{
	//Check if the overlapping actor is the players vehicle
	if (ABaseVehicle* Player = Cast<ABaseVehicle>(OverlappingActor))
	{
		//add some time to the players clock.
		Player->CheckPointHit();
		if (isStart) {
			Player->Lap();
		}
	}
}

void ACheckPoint::OnVolumeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OverlappingActor, UPrimitiveComponent* OtherComponent, int32 index)
{
}

