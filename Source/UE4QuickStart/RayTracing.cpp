// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

#include "RayTracing.h"

#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "UE4QuickStart.h"


// Sets default values
ARayTracing::ARayTracing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARayTracing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARayTracing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Do not trace each tick (an event or a timer would be more efficient in real usage)
	TimeSinceLastTrace += DeltaTime;
	if (TimeSinceLastTrace >= 0.25f)
	{
		TraceLine();
		TimeSinceLastTrace = 0.0f;
	}
}

// Cast a ray accross the level
void ARayTracing::TraceLine()
{
	// Find the actor that handles control for the local player.
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		FVector Location;
		FRotator Rotation;
		PlayerController->GetPlayerViewPoint(Location, Rotation);
	//	const AActor* Camera = PlayerController->GetViewTarget();
	//	Camera->GetActorEyesViewPoint(Location, Rotation);
		const FVector TraceStart = Location;
		const FVector TraceEnd = TraceStart + Rotation.Vector() * Length;

		// AActor* Camera = PlayerController->GetViewTarget();
		const AActor* ActorToIgnore = nullptr;

	//	UE_LOG(QuickStart, Log, TEXT("ARayTracing: TraceStart [%f, %f, %f]"), TraceStart.X, TraceStart.Y, TraceStart.Z);
	//	UE_LOG(QuickStart, Log, TEXT("ARayTracing: TraceEnd [%f, %f, %f]"), TraceEnd.X, TraceEnd.Y, TraceEnd.Z);

		FCollisionQueryParams TraceParams(FName(TEXT("RayTracing")), true, ActorToIgnore);
		TraceParams.bReturnPhysicalMaterial = false;
		TraceParams.bTraceComplex = true;

		FHitResult HitResult(ForceInit);
		
		const bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, TraceParams);
	//	UE_LOG(QuickStart, Log, TEXT("ARayTracing: LineTraceSingleByChannel bHit=%d Actor=%x"), bHit, HitResult.GetActor());

		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 1.0f);

		// Print out the name of the traced actor
		if (HitResult.GetActor())
		{
			UE_LOG(QuickStart, Log, TEXT("ARayTracing: ActorName=%s Distance=%f"), *HitResult.GetActor()->GetName(), HitResult.Distance);
		}
	}
}
