// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

// This is a list of gameplay tags that are common throughout the game.
namespace WarriorGameplayTags
{
	/** Input Tag */
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move)
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)

	/** Player tags */
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe)
}
