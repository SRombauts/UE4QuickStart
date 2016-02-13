// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4QuickStart.h"
#include "BatteryPickup.h"


//Set default values
ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}
