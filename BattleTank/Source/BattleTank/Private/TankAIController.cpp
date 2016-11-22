// Copyright Joe Fernandez 2016

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(PlayerTank)) { return; }

	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim towards Player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// Fire if Ready
	AimingComponent->Fire(); // TODO limit firing rate
}