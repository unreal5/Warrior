// Copyright Epic Games, Inc. All Rights Reserved.

#include "WarriorHeroCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputSubsystems.h"
#include "WarriorGameplayTags.h"
#include "Component/Input/WarriorInputComponent.h"


AWarriorHeroCharacter::AWarriorHeroCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 55.0f, 65.0f);
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

void AWarriorHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Super::SetupPlayerInputComponent(PlayerInputComponent);
	UWarriorInputComponent* EnhancedInputComponent = CastChecked<UWarriorInputComponent>(PlayerInputComponent);
	if (!EnhancedInputComponent) return;

	APlayerController* PlayerController = GetController<APlayerController>();
	if (!PlayerController) return;

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		PlayerController->GetLocalPlayer());
	if (!Subsystem) return;

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
	EnhancedInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Move,
	                                              ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	EnhancedInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Look,
	                                              ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}

void AWarriorHeroCharacter::Input_Move(const FInputActionValue& Value)
{
	FVector2D MovementInput = Value.Get<FVector2D>();
	if (MovementInput.IsNearlyZero()) return;
	FRotator WorldRotation{0.f, GetControlRotation().Yaw, 0.f};
	FVector MovementDirection{MovementInput.Y, MovementInput.X, 0.f};
	MovementDirection = WorldRotation.RotateVector(MovementDirection);
	AddMovementInput(MovementDirection);
}

void AWarriorHeroCharacter::Input_Look(const FInputActionValue& Value)
{
	FVector2D LookDirection = Value.Get<FVector2D>();
	if (LookDirection.IsNearlyZero()) return;
	AddControllerPitchInput(LookDirection.Y);
	AddControllerYawInput(LookDirection.X);
}
