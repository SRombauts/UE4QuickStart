// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "Components/ActorComponent.h"
#include "LocationReporterComponent.generated.h"


// Simple component producing a Log on BeginPlay with name and location of owning Actor
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4QUICKSTART_API ULocationReporterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULocationReporterComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
//	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
};
