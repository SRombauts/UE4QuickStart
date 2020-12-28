// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

#include "LocationReporterComponent.h"

#include "UE4QuickStart.h"


// Sets default values for this component's properties
ULocationReporterComponent::ULocationReporterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void ULocationReporterComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get Actor owning this Component (cannot be nullptr)
	const AActor& OwningActor = *GetOwner();
	UE_LOG(QuickStart, Log, TEXT("ULocationReporterComponent::BeginPlay(%s) at location %s"), *OwningActor.GetName(), *OwningActor.GetActorLocation().ToString());
}


/* Called every frame
void ULocationReporterComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}
*/
