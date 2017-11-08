// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"


void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	//Check if the tank is possessed
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find Player Tank!"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player Tank: %s"), *(PlayerTank->GetName()));
	}

}

ATank* ATankAIController::GetAIControlledTank() const {

	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const {

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;  }
	return Cast<ATank>(PlayerPawn);
}

