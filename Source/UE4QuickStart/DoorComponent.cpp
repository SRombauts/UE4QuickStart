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

	// At this stage, the World should always exists
	const UWorld* const World = GetWorld();
	if (World)
	{
		const APlayerController* const OurPlayerController = World->GetFirstPlayerController();
		if (OurPlayerController)
		{
			OpenerPawn = OurPlayerController->GetPawn();
		}
	}
}


// Called every frame
void UDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const UWorld* const World = GetWorld();
	if (World)
	{
		const float CurrentTime = World->GetTimeSeconds();
		if (Trigger)
		{
			if (Trigger->IsOverlappingActor(OpenerPawn))
			{
				OpenDoor();
				TimeOfOpening = CurrentTime;
			}
			else
			{
				if (CurrentTime > TimeOfOpening + DelayToClose)
				{
					CloseDoor();
				}
			}
		}
	}
}


void UDoorComponent::OpenDoor()
{
	Door->SetActorRotation(FRotator(0.f, Angle, 0.f));
}

void UDoorComponent::CloseDoor()
{
	Door->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}
