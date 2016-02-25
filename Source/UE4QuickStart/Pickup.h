// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sebastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class UE4QUICKSTART_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
//	virtual void Tick( float DeltaSeconds ) override;

	// Return the Mesh
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

private:
	// Static mesh to represent the Pickup in the level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
};
