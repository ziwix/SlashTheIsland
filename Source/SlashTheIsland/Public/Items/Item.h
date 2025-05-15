// © 2025 Highland Studio. All rights reserved.
//Slash and all associated assets — including characters, story, code, and visuals — are the intellectual property of Highland Studio.
//Unauthorized use, reproduction, or distribution of this content is strictly prohibited.

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

	//Declares if the movement of the item is set to be circular
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters")
	bool bCircleMovement = false;

	//Declares the phase shift for the sine wave
	UFUNCTION(BlueprintPure)
	float TransformedSin();

	//Declares the amplitude for the cosine wave
	UFUNCTION(BlueprintPure)
	float TransformedCos();

	//Declares the movement rate for the X axis of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters", meta = (EditCondition = "!bCircleMovement"))
	float MovementRateX = 10.f;

	//Declares the movement rate for the Y axis of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters", meta = (EditCondition = "!bCircleMovement"))
	float MovementRateY = 10.f;

	//Declares the movement rate for the Z axis of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters")
	float MovementRateZ = 10.f;

	//Declares the movement rate for the pitch of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters")
	float MovementRatePitch = 10.f;

	//Declares the movement rate for the yaw of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters")
	float MovementRateYaw = 10.f;

	//Declares the movement rate for the roll of the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movements Parameters")
	float MovementRateRoll = 10.f;

	//Declares if it should draw a Debug Sphere
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool bEnableDebugSphere = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug", meta = (EditCondition = "bEnableDebugSphere", EditConditionHides))
	float DebugSize = 25.f;

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
