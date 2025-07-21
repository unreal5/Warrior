// 版权没有，拷贝自由。


#include "DataAsset_EnemyStartUpData.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Ability/WarriorEnemyGameplayAbility.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASC,
                                                               int32 InApplyLevel) const
{
	Super::GiveToAbilitySystemComponent(InASC, InApplyLevel);
	if (EnemyCombatAbilities.IsEmpty()) return;
	
	for (const auto& AbilityClass : EnemyCombatAbilities)
	{
		if (!AbilityClass) continue;

		FGameplayAbilitySpec AbilitySpec{AbilityClass, InApplyLevel};
		AbilitySpec.SourceObject = InASC->GetAvatarActor();

		InASC->GiveAbility(AbilitySpec);
	}
}
