// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SLASHTHEISLAND_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Declares the amplitude for the sine wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;

	//Declares the frequency for the sine wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.f;

	//Declares the phase shift for the sine wave
	UFUNCTION(BlueprintPure)
	float TransformedSin();

	//Declares the amplitude for the cosine wave
	UFUNCTION(BlueprintPure)
	float TransformedCos();

	//Declares the movement rate for the pitch of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters")
	float MovementRatePitch = 10.f;

	//Declares the movement rate for the yaw of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters")
	float MovementRateYaw = 10.f;

	//Declares the movement rate for the roll of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters")
	float MovementRateRoll = 10.f;

	//Declares temlate function to calculate the average of two values
	template<typename T>
	T Avg(T First, T Second);

private:
	//Declares the running time for the item
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	//Declares the root component for the item
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;
};

//Template function to calculate the average of two values
template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
