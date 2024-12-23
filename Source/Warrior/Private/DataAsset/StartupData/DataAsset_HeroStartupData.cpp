// 高级动作RPG游戏


#include "DataAsset/StartupData/DataAsset_HeroStartupData.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"



void UDataAsset_HeroStartupData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive,
	int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const auto& AbilitySet : HeroStartupAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;
		
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant, ApplyLevel);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		//AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
