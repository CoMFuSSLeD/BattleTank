// Copyright Joe Fernandez 2016

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movement, +1 is max upward movement
	void Elevate(float RelativeSpeed);
	
private:
	// Defaults
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10; 
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 35;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0;
};
