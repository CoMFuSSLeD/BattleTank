// Copyright Joe Fernandez 2016

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declarations
class UTankBarrel;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BluePrintCallable, Category = "Setup")
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BluePrintCallable, Category = "Setup")
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BluePrintCallable, Category = "Firing")
	void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; // Current 40 m/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local reference for spawning a projectile
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
