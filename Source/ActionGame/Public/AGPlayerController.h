// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActionGame.h"
#include "GameFramework/PlayerController.h"
#include "AGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGAME_API AAGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAGPlayerController();

protected:
	bool bIsTargetUpdated = false;

	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	void MoveOrUsePrimarySkill();
	void SetNewMoveDestination(const FVector DestLocation);

	void OnLeftMousePressed();
	void OnLeftMouseReleased();
};
