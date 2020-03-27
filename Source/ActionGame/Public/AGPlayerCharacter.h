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

	/**
	@fn bool GetCursorLocation(_Outptr_result_maybenull_ AAGCharacter* TargetCharacter, _Outref_ FVector& TargetLocation);
	@brief Get mouse cursor location on world.
	@date 2020/03/28
	@author Lee JeongGil (lee-jeonggil@naver.com)
	@param TargetCharacter Character pointer to be returned.
	@param TargetLocation Vector ref to be returned.
	@return If there is a character, return true. Else, return false and TargetCharacter is nullptr.
	@remark Used to get mouse cursor location. If there is a character under the cursor, return true and TargetCharamcter points nullptr.
	@todo AAGCharacter should be changed. After enemy or destructible object class added, change to them. TraceChannel should be added.
	*/
	bool GetCursorLocation(_Outptr_result_maybenull_ AAGCharacter* TargetCharacter, _Outref_ FVector& TargetLocation);

	void Front(float NewAxisValue);
	void Right(float NewAxisValue);
	void TurnClockwise(float NewAxisValue);
	void LookUp(float NewAxisValue);
};
