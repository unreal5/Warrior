#pragma once

#include "WarriorEnumTypes.generated.h"

UENUM()
enum class EWarriorConfirmType : uint8
{
	Yes,
	No,
};

UENUM()
enum class EWarriorValidType : uint8
{
	Valid,
	Invalid,
};

UENUM(BlueprintType)
enum EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand,
};
