// Fill out your copyright notice in the Description page of Project Settings.


#include "AGPlayerCharacter.h"

AAGPlayerCharacter::AAGPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -GetDefaultHalfHeight()), FRotator(0.f, -90.f, 0.f));
}

void AAGPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Camera Settings
	SpringArm->TargetArmLength = CameraArmLength;
	SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritRoll = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bDoCollisionTest = true;
	bUseControllerRotationYaw = true;
}

void AAGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Front"), this, &AAGPlayerCharacter::Front);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AAGPlayerCharacter::Right);
	PlayerInputComponent->BindAxis(TEXT("TurnClockWise"), this, &AAGPlayerCharacter::TurnClockwise);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AAGPlayerCharacter::LookUp);
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);
}

bool AAGPlayerCharacter::GetCursorLocation(AAGCharacter* TargetCharacter, FVector& TargetLocation)
{
	FHitResult* Hit;
	APlayerController* PC;
	PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		//PC->GetHitResultUnderCursorByChannel
	}

	return false;
}

void AAGPlayerCharacter::Front(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
}

void AAGPlayerCharacter::Right(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
}

void AAGPlayerCharacter::TurnClockwise(float NewAxisValue)
{
	AddControllerYawInput(NewAxisValue);
}

void AAGPlayerCharacter::LookUp(float NewAxisValue)
{
	AddControllerPitchInput(NewAxisValue);
}
