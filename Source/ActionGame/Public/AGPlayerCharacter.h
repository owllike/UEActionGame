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

	virtual void Tick(float DeltaSeconds) override;

	FORCEINLINE class UCameraComponent* GetCamera() const { return Camera; }
	FORCEINLINE class USpringArmComponent* GetSpringArm() const { return SpringArm; }
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	// A decal that projects to the cursor location.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UDecalComponent* CursorToWorld;
};
