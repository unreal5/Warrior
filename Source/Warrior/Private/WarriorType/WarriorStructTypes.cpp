// 高级动作RPG游戏

#include "WarriorType/WarriorStructTypes.h"

#include "AbilitySystem/Ability/WarriorHeroGameplayAbility.h"


bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
