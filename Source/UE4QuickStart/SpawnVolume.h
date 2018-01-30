// UE4 C++ Quick Start Tutorials - copyright 2015-2018 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class UE4QUICKSTART_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
//	virtual void Tick( float DeltaSeconds ) override;

	// Return the Mesh representing the SpawnVolume
	FORCEINLINE class UBoxComponent* GetMesh() const { return WhereToSpawn; }

	// Find a random point inside the SpawnVolume
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

protected:
	// The Pickup to spawn
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

	FTimerHandle SpawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float MinimumSpawnDelay = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float MaximumSpawnDelay = 5.0f;

private:
	// Static mesh to represent the SpawnVolume in the level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;

	// Spawn a new Pickup
	void SpawnPickup();
};
