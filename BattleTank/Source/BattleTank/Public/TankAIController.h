// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declarations 
class ATank;

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
