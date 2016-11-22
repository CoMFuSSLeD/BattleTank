// Copyright Joe Fernandez 2016

#include "BattleTank.h"
#include "Tank.h"
#include "TankMovementComponent.h"
#include "TankAIController.h"


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (ensure(PlayerTank)) 
	{ 
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim towards Player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if Ready
		ControlledTank->Fire(); // TODO limit firing rate
	}
}