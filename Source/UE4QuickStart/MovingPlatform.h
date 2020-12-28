// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UE4QUICKSTART_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	UPROPERTY(EditAnyWhere, Category = "Destination")
	AActor* TargetActor = nullptr;

	FVector StartLocation;
	FVector TargetLocation;
	float Alpha = 0.0f;

	bool bMoving = false;
	FTimerHandle StartTimerHandle;
	void StartMoving();
};
