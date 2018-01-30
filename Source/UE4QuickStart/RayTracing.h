// UE4 C++ Quick Start Tutorials - copyright 2015-2018 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Actor.h"
#include "RayTracing.generated.h"

// Ray Cast / Line Trace
UCLASS()
class UE4QUICKSTART_API ARayTracing : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARayTracing();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:	
	// Lenght of ray tracing. Defaults to 10m.
	UPROPERTY(EditAnywhere)
	float Length = 1000.f;

	// Cast a ray accross the level
	void TraceLine();
	float TimeSinceLastTrace = 0.0f;
};
