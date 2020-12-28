// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

#include "MyPawn.h"

#include "Camera/CameraComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Create a camera
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	// Attach our camera to our root component. Offset and rotate the camera.
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	// Create a visible object and attach it to the root component.s
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

	CurrentVelocity = FVector(0.f);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// Handle growing and shrinking based on our "Grow" action
	{
		float CurrentScale = OurVisibleComponent->GetComponentScale().X;
		if (bGrowing)
		{
			// Grow to double size over the course of one second
			CurrentScale += DeltaTime;
		}
		else
		{
			// Shrink half as fast as we grow
			CurrentScale -= (DeltaTime * 0.5f);
		}
		// Make sure we never drop below our starting size, or increase past double size.
		CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f);
		OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
	}

	// Handle movement based on our "MoveX" and "MoveY" axes
	{
		CurrentVelocity.X = FMath::Clamp(CurrentVelocity.X + (CurrentAcceleration.X * DeltaTime), -1000.f, 1000.f);
		CurrentVelocity.Y = FMath::Clamp(CurrentVelocity.Y + (CurrentAcceleration.Y * DeltaTime), -1000.f, 1000.f);

		if (!CurrentVelocity.IsZero())
		{
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
			SetActorLocation(NewLocation);
		}
	}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Respond when our "Grow" key is pressed or released.
	InputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);
	InputComponent->BindAction("Grow", IE_Released, this, &AMyPawn::StopGrowing);

	// Respond every frame to the values of our two movement axes, "MoveX" and "MoveY".
	InputComponent->BindAxis("MoveX", this, &AMyPawn::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &AMyPawn::Move_YAxis);
}

void AMyPawn::Move_XAxis(float AxisValue)
{
	if ((0.f != AxisValue) || (0.f == CurrentVelocity.X))
	{
		// Accelerate at 200 units per second forward or backward
		CurrentAcceleration.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 200.0f;
	}
	else
	{
		// Deccelerate at 500 units per second forward or backward
		CurrentAcceleration.X = FMath::Clamp(CurrentVelocity.X, -1.0f, 1.0f) * -500.0f;
	}
}

void AMyPawn::Move_YAxis(float AxisValue)
{
	if ((0.f != AxisValue) || (0.f == CurrentVelocity.Y))
	{
		// Accelerate at 200 units per second forward or backward
		CurrentAcceleration.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 200.0f;
	}
	else
	{
		// Deccelerate at 500 units per second forward or backward
		CurrentAcceleration.Y = FMath::Clamp(CurrentVelocity.Y, -1.0f, 1.0f) * -500.0f;
	}
}

void AMyPawn::StartGrowing()
{
	bGrowing = true;
}

void AMyPawn::StopGrowing()
{
	bGrowing = false;
}
