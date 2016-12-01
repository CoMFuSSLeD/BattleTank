// Copyright Joe Fernandez 2016

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
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
	if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
	{
		AimingComponent->Fire(); // TODO limit firing rate
	}
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// Subscribe local method to tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();	
}
