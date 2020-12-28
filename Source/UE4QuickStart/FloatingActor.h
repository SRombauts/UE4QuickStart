// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

/// Uses Tick with sine to move/float smoothly in loop (https://docs.unrealengine.com/latest/INT/Programming/QuickStart/index.html)
UCLASS()
class UE4QUICKSTART_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

	/// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	/// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	/// Period of the floating movement, in seconds
	UPROPERTY(EditAnywhere, Category = "Floating Movement")
	FVector Period = { 1.2f, 0.8f, 1.0f };

	/// Scale of the movement, in units (centimeters)
	UPROPERTY(EditAnywhere, Category = "Floating Movement")
	FVector Scale = { 10.0f, 10.0f, 20.0f };

	/// Slowly rotate    (Pitch, Yaw, Roll)
	UPROPERTY(EditAnywhere, Category = "Floating Movement")
	FRotator Rotation = { 0.0f, 0.0f, 3.0f };

	float RunningTime = 0.0f;
};
