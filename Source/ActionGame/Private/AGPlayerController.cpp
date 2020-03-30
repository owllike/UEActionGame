// Fill out your copyright notice in the Description page of Project Settings.


#include "AGPlayerController.h"
#include "AGPlayerCharacter.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AAGPlayerController::AAGPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AAGPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (bIsTargetUpdated)
	{
		MoveOrUsePrimarySkill();
	}
}

void AAGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouse", IE_Pressed, this, &AAGPlayerController::OnLeftMousePressed);
	InputComponent->BindAction("LeftMouse", IE_Released, this, &AAGPlayerController::OnLeftMouseReleased);
}

void AAGPlayerController::MoveOrUsePrimarySkill()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);	// Use GetHitResultUnderCursorByChannel later
	
	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void AAGPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AAGPlayerController::OnLeftMousePressed()
{
	bIsTargetUpdated = true;
}

void AAGPlayerController::OnLeftMouseReleased()
{
	bIsTargetUpdated = false;
}
