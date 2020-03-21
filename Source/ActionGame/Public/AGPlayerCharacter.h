// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActionGame.h"
#include "AGCharacter.h"
#include "AGPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGAME_API AAGPlayerCharacter : public AAGCharacter
{
	GENERATED_BODY()
	
public:
	AAGPlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnyWhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnyWhere, Category = Camera)
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnyWhere, Category = Camera)
	float CameraArmLength = 450.f;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Front(float NewAxisValue);
	void Right(float NewAxisValue);
	void TurnClockwise(float NewAxisValue);
	void LookUp(float NewAxisValue);
};
