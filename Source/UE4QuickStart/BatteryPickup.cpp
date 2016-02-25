// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sebastien Rombauts - distributed under the MIT License

#include "UE4QuickStart.h"
#include "BatteryPickup.h"


// Set default values
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}
