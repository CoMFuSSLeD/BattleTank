// Copyright Joe Fernandez 2016

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// How Close an AI tank will get to a player
	float AcceptanceRadius = 3000;
};
