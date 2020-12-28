// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

#include "MovingPlatform.h"

#include "UE4QuickStart.h"


// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(StartTimerHandle, this, &AMovingPlatform::StartMoving, 2.0f);

	StartLocation = GetActorLocation();
	if (nullptr != TargetActor)
	{
		TargetLocation = TargetActor->GetActorLocation();
	}
	else
	{
		TargetLocation = StartLocation;
	}

	UE_LOG(QuickStart, Log, TEXT("AMovingPlatform::BeginPlay()"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "AMovingPlatform::BeginPlay()");
	}
}

// Called every frame
void AMovingPlatform::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (bMoving)
	{
		const float InterpSpeed = 0.5f; // Needs 2 seconds to reach Target
		Alpha += DeltaTime * InterpSpeed;
		Alpha = FMath::Clamp(Alpha, 0.0f, 1.0f);
		const FVector InterpLocation = FMath::Lerp(StartLocation, TargetLocation, Alpha);
		const FVector CurrentLocation = GetActorLocation();
		if (!InterpLocation.Equals(TargetLocation))
		{
			SetActorLocation(InterpLocation);
		}
		else
		{
			// Swap(StartLocation, TargetLocation) to go back and forth between Start and Target Location
			const FVector TempLocation = TargetLocation;
			TargetLocation = StartLocation;
			StartLocation = TempLocation;
			Alpha = 0.0f;

			bMoving = false;
			GetWorldTimerManager().SetTimer(StartTimerHandle, this, &AMovingPlatform::StartMoving, 2.0f);
		}
	}
}

// Called by the time to start moving the platform
void AMovingPlatform::StartMoving()
{
	bMoving = true;
}
