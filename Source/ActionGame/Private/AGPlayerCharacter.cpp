// Fill out your copyright notice in the Description page of Project Settings.


#include "AGPlayerCharacter.h"
#include "Components/DecalComponent.h"

AAGPlayerCharacter::AAGPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;	// Rotate character to moving direction
	//GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a SpringArm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	SpringArm->SetupAttachment(GetCapsuleComponent());
	SpringArm->SetUsingAbsoluteRotation(true);	// Don't want arm to rotate when character does
	//SpringArm->TargetArmLength = 800.f;
	//SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	SpringArm->bDoCollisionTest = false;	// Don't want to pull camera in when it collides with level

	// Create a Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	//// Create a decal in the world to show the cursor's location
	//CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CURSORTOWORLD");
	//CursorToWorld->SetupAttachment(GetCapsuleComponent());
	//static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	//if (DecalMaterialAsset.Succeeded())
	//{
	//	CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	//}
	//CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	//CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -GetDefaultHalfHeight()), FRotator(0.f, -90.f, 0.f));
}

void AAGPlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void AAGPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}
