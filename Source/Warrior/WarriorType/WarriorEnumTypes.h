#pragma once
#include "WarriorEnumTypes.generated.h"

UENUM(BlueprintType)
enum class EWarriorConfirmType : uint8
{
	Yes UMETA(DisplayName = "Yes"),
	No UMETA(DisplayName = "No"),
};

UENUM(BlueprintType)
enum class EWarriorValidType : uint8
{
	Valid UMETA(DisplayName = "Valid"),
	Invalid UMETA(DisplayName = "Invalid"),
};

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand,
};