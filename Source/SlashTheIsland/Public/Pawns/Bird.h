// © 2025 Highland Studio. All rights reserved.
//Slash and all associated assets — including characters, story, code, and visuals — are the intellectual property of Highland Studio.
//Unauthorized use, reproduction, or distribution of this content is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bird.generated.h"

// Forward declaration of UCapsuleComponent to avoid circular dependency
class UCapsuleComponent;
// Forward declaration of USkeletalMeshComponent to avoid circular dependency
class USkeletalMeshComponent;

UCLASS()
class SLASHTHEISLAND_API ABird : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABird();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// Declare the capsule component
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* BirdMesh;
};
