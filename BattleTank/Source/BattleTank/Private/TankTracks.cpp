// Copyright Joe Fernandez 2016

#include "BattleTank.h"
#include "TankTracks.h"



void UTankTracks::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TankMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

