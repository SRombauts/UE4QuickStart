// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

#include "Pickup.h"

#include "UE4QuickStart.h"


// Sets default values
APickup::APickup()
{
 	// This actor does not need to call Tick() every frame, this improves performance.
	PrimaryActorTick.bCanEverTick = false;

	// Create the static mesh component
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
}

/* Called every frame, but NOT when PrimaryActorTick.bCanEverTick = false
void APickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}
*/
