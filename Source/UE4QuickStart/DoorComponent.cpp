// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sebastien Rombauts - distributed under the MIT License

#include "UE4QuickStart.h"
#include "DoorComponent.h"


// Sets default values for this component's properties
UDoorComponent::UDoorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UDoorComponent::BeginPlay()
{
	Super::BeginPlay();

	Door = GetOwner();
	OpenDoor();
}


// Called every frame
void UDoorComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}


void UDoorComponent::OpenDoor()
{
	Door->SetActorRotation(FRotator(0.f, Angle, 0.f));
}

void UDoorComponent::CloseDoor()
{
	Door->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}
