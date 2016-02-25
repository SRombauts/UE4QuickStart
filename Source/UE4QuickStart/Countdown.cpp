// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sebastien Rombauts - distributed under the MIT License

#include "UE4QuickStart.h"
#include "Countdown.h"


// Sets default values
ACountdown::ACountdown()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>((TEXT("CountdownNumber")));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	RootComponent = CountdownText;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();

	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);

	UE_LOG(QuickStart, Log, TEXT("ACountdown::BeginPlay()"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "ACountdown::BeginPlay()");
	}
}

// Called every frame
void ACountdown::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACountdown::UpdateTimerDisplay()
{
	CountdownText->SetText(FText::FromString(FString::FromInt(FMath::Max(CountdownTime, 0))));
}

void ACountdown::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();
	if (CountdownTime < 1)
	{
		// We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		// Perform any special actions we want to do when the timer ends.
		CountdownHasFinished();
	}
}

void ACountdown::CountdownHasFinished_Implementation()
{
	// Change to a special readout
	CountdownText->SetText(FText::FromString(TEXT("GO!")));
	UE_LOG(QuickStart, Log, TEXT("ACountdown::CountdownHasFinished_Implementation()"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "ACountdown::CountdownHasFinished_Implementation()");
	}
}
