// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Actor.h"
#include "Countdown.generated.h"

UCLASS()
class UE4QUICKSTART_API ACountdown : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACountdown();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called when count get to zero
	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();

private:
	// How long, in seconds, the countdown will run
	UPROPERTY(EditAnywhere)
	int32 CountdownTime = 3;

	// C++ default implementation (if no implementation given by Blueprint) Can be called from Blueprint using "Parent: CountdownHasFinished"
	virtual void CountdownHasFinished_Implementation();

	UTextRenderComponent* CountdownText = nullptr;

	FTimerHandle CountdownTimerHandle;

	void UpdateTimerDisplay();

	void AdvanceTimer();
};
