// Copyright Joe Fernandez 2016

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/*
* TankTracks is used to set a maximum driving force and to apply forces to the tank.
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float TankMaxDrivingForce = 400000; // Assume 40 ton tank and 1g acceleration
};
