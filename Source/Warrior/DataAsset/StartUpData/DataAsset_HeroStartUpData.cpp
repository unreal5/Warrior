// 版权没有，拷贝自由。


#include "DataAsset_HeroStartUpData.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"



void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASC,
	int32 InApplyLevel) const
{
	Super::GiveToAbilitySystemComponent(InASC, InApplyLevel);

	for (const auto& AbilitySet : HeroStartUpAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASC->GetAvatarActor();
		AbilitySpec.Level = InApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

		InASC->GiveAbility(AbilitySpec);
	}
}
