// UE4 C++ Quick Start Tutorials - copyright 2015-2018 Sebastien Rombauts - distributed under the MIT License

#include "UE4QuickStart.h"
#include "SpawnVolume.h"
#include "Pickup.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
	// This actor does not need to call Tick() every frame, this improves performance.
	PrimaryActorTick.bCanEverTick = false;

	// Create the static mesh component
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	// Start a timer to spawn a new Pickup after a delay
	const float SpawnDelay = FMath::RandRange(MinimumSpawnDelay, MaximumSpawnDelay);
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
	UE_LOG(QuickStart, Log, TEXT("ASpawnVolume(%s)::SetTimer(%f)"), *WhatToSpawn->GetName(), SpawnDelay);
}

/* Called every frame, but NOT when PrimaryActorTick.bCanEverTick = false
void ASpawnVolume::Tick( float DeltaTime )
{
Super::Tick( DeltaTime );

}
*/

FVector ASpawnVolume::GetRandomPointInVolume()
{
	const FVector& SpawnOrigin = WhereToSpawn->Bounds.Origin;
	const FVector& SpawnExtent = WhereToSpawn->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

void ASpawnVolume::SpawnPickup()
{
	// If we have something to spawn
	if (nullptr != WhatToSpawn)
	{
		// Check for a valid World
		UWorld* const World = GetWorld();
		if (nullptr != World)
		{
			// Set the spawn parameters
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			// Get a random location and a random rotation
			const FVector SpawnLocation = GetRandomPointInVolume();
			const FRotator SpawnRotation = UKismetMathLibrary::RandomRotator(true);

			// Spawn the pickup
			APickup* const SpawndPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

			// Start a timer to spawn a new Pickup after a delay
			const float SpawnDelay = FMath::RandRange(MinimumSpawnDelay, MaximumSpawnDelay);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
			UE_LOG(QuickStart, Log, TEXT("ASpawnVolume(%s): SetTimer(%f)"), *WhatToSpawn->GetName(), SpawnDelay);
		}
	}
}

