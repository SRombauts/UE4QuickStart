// UE4 C++ Quick Start Tutorials - copyright 2015-2018 Sebastien Rombauts - distributed under the MIT License

#include "UE4QuickStart.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(QuickStart, Log, TEXT("AFloatingActor::BeginPlay()"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "AFloatingActor::BeginPlay()");
	}
}

// Called every frame: uses a sinusoid mathematical function to loop periodically across time
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

	FVector Offset;
	Offset.X = (FMath::Sin((RunningTime + DeltaTime) * Period.X) - FMath::Sin(RunningTime * Period.X)) * Scale.X;
	Offset.Y = (FMath::Sin((RunningTime + DeltaTime) * Period.Y) - FMath::Sin(RunningTime * Period.Y)) * Scale.Y;
	Offset.Z = (FMath::Sin((RunningTime + DeltaTime) * Period.Z) - FMath::Sin(RunningTime * Period.Z)) * Scale.Z;
	RunningTime += DeltaTime;

	AddActorLocalOffset(Offset);

	AddActorLocalRotation(Rotation * DeltaTime);
}

