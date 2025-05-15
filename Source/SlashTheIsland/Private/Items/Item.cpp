// © 2025 Highland Studio. All rights reserved.
//Slash and all associated assets — including characters, story, code, and visuals — are the intellectual property of Highland Studio.
//Unauthorized use, reproduction, or distribution of this content is strictly prohibited.

#include "Items/Item.h"
#include "SlashTheIsland/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a static mesh component and set it as the root component
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called to calculate the transformed sine value
float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

// Called to calculate the transformed cosine value
float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Calculate the running time
	RunningTime += DeltaTime;

	// Show DeltaTime
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString::Printf(TEXT("DeltaTime : %f"), DeltaTime));

	// Add offset to the item mesh
	if (bCircleMovement)
		AddActorWorldOffset(FVector(TransformedSin(), TransformedCos(), MovementRateZ * DeltaTime));
	else
		AddActorWorldOffset(FVector(MovementRateX * DeltaTime, MovementRateY * DeltaTime, MovementRateZ * DeltaTime));

	// Draw debug sphere with a forward vector
	if (bEnableDebugSphere)
	{
		DRAW_DEBUG_SPHERE_SingleFrame(GetActorLocation(), DebugSize)
		DRAW_DEBUG_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * (DebugSize * 1.5f), DebugSize * 0.25f)
	}

	// Add rotation to the item mesh
	AddActorWorldRotation(FRotator(MovementRatePitch * DeltaTime, MovementRateYaw * DeltaTime, MovementRateRoll * DeltaTime));
}

