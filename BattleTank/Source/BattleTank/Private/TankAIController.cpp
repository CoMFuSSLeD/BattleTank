// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank) 
	{ 
		// TODO Move towards player

		// Aim towards Player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if Ready
		ControlledTank->Fire(); // TODO limit firing rate
	}
}