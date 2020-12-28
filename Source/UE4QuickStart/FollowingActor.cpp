// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

#include "FollowingActor.h"

#include "UE4QuickStart.h"


// Sets default values
AFollowingActor::AFollowingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFollowingActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(QuickStart, Log, TEXT("AFollowingActor::BeginPlay()"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, "AFollowingActor::BeginPlay()");
	}
}

// Called every frame
void AFollowingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bFollowing && (nullptr != TargetActor))
	{
		const float InterpSpeed = 1.0f;
		const FVector CurrentLocation = GetActorLocation();
		const FVector InterpLocation = FMath::VInterpTo(CurrentLocation, TargetActor->GetActorLocation(), DeltaTime, InterpSpeed);
		const bool bSweep = false; // Do NOT perform collision detection (this is the default)

		SetActorLocation(InterpLocation, bSweep);
	}
}

