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
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Component/Combat/HeroCombatComponent.h"
#include "Component/Input/WarriorInputComponent.h"
#include "DataAsset/StartUpData/DataAsset_StartUpDataBase.h"


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

	// Create the combat component
	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
}

void AWarriorHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Super::SetupPlayerInputComponent(PlayerInputComponent);
	UWarriorInputComponent* WarriorInputComponent = CastChecked<UWarriorInputComponent>(PlayerInputComponent);
	if (!WarriorInputComponent) return;

	APlayerController* PlayerController = GetController<APlayerController>();
	if (!PlayerController) return;

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		PlayerController->GetLocalPlayer());
	if (!Subsystem) return;

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Move,
	                                             ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Look,
	                                             ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

	WarriorInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed,
	                                              &ThisClass::Input_AbilityInputReleased);
}

void AWarriorHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	// 对于软引用，应检查IsNull而不是IsValid()；
	// IsValid()会检查指针是否为nullptr，但软引用可能是有效的，但指向的对象未加载。
	if (!CharacterStartUpData.IsNull())
	{
		// 同步加载
		if (auto LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);
		}
	}
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

void AWarriorHeroCharacter::Input_AbilityInputPressed(FGameplayTag InputTag)
{
	GetWarriorAbilitySystemComponent()->OnAbilityInputPressed(InputTag);
}

void AWarriorHeroCharacter::Input_AbilityInputReleased(FGameplayTag InputTag)
{
	GetWarriorAbilitySystemComponent()->OnAbilityInputReleased(InputTag);
}
