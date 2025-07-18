// 版权没有，拷贝自由。


#include "WarriorStructTypes.h"

#include "AbilitySystem/Ability/WarriorHeroGameplayAbility.h"


bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant != nullptr;
}
