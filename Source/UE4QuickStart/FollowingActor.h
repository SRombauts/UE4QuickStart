// UE4 C++ Quick Start Tutorials - copyright 2015-2018 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Actor.h"
#include "FollowingActor.generated.h"

UCLASS()
class UE4QUICKSTART_API AFollowingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFollowingActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	UPROPERTY(EditAnyWhere, Category = "Destination")
	AActor* TargetActor = nullptr;

	UPROPERTY(EditAnyWhere, Category = "Destination")
	bool bFollowing = true;
};
