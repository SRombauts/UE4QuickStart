// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class UE4QUICKSTART_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	UPROPERTY(EditAnywhere, Category = "Floating Movement")
	FVector Period = { 1.2f, 0.8f, 1.0f };

	UPROPERTY(EditAnywhere, Category = "Floating Movement")
	FVector Scale = { 10.0f, 10.0f, 20.0f };

	//                    Pitch, Yaw, Roll
	UPROPERTY(EditAnywhere, Category = "Floating Movement")
	FRotator Rotation = { 0.0f, 0.0f, 3.0f };

	float RunningTime = 0.0f;
};
