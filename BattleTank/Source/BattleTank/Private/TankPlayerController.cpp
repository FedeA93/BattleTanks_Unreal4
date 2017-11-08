
#include "TankPlayerController.h"
#include "BattleTank.h"


void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	//Check if the tank is possessed
	if (!ControlledTank) { 
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank!"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"),*(ControlledTank->GetName()));
	}

}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	//TODO AimTowardsCrosshair()
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Ticking!"));
}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());

}




