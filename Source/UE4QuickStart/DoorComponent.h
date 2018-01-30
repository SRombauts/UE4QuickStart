// UE4 C++ Quick Start Tutorials - copyright 2015-2018 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "Components/ActorComponent.h"
#include "DoorComponent.generated.h"


// Component to add to an Actor to enable it to be open with a rotation
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4QUICKSTART_API UDoorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	void OpenDoor();
	void CloseDoor();

	// The Actor door that own this Component
	UPROPERTY(VisibleAnywhere)
	AActor* Door = nullptr;

	// The Pawn that can open the door
	UPROPERTY(VisibleAnywhere)
	APawn* OpenerPawn = nullptr;

	// The Volume trigger that can open the door
	UPROPERTY(EditAnywhere)
	ATriggerVolume* Trigger = nullptr;

	// Angle of rotation (degrees) to apply to the door when openned (0° when closed)
	UPROPERTY(EditAnywhere)
	float Angle = 80.f;

	// Time to leave the door open
	UPROPERTY(EditAnywhere)
	float DelayToClose = 1.f;

	// Time of when the door was opened
	float TimeOfOpening = 0.f;
};
