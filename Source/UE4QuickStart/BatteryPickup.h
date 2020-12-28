// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class UE4QUICKSTART_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABatteryPickup();
};
