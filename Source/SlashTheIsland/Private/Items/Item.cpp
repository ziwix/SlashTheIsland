// Fill out your copyright notice in the Description page of Project Settings.


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

	// Add rotation to the item mesh
	AddActorWorldRotation(FRotator(MovementRatePitch * DeltaTime, MovementRateYaw * DeltaTime, MovementRateRoll * DeltaTime));
}

