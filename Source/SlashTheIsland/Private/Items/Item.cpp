// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "SlashTheIsland/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	FVector Location = GetActorLocation();
	FVector EndLocation = Location + GetActorForwardVector() * 100.f;

	DRAW_ACTOR_DEBUG(Location, EndLocation)
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

