// UE4 C++ Quick Start Tutorials - copyright 2015-2018 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class UE4QUICKSTART_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
	// Static mesh to represent the Pawn in the level
	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

private:
	// Input functions
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	void StartGrowing();
	void StopGrowing();

	// Input variables
	FVector CurrentAcceleration;
	FVector CurrentVelocity;
	bool bGrowing;
};
