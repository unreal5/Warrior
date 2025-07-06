// 版权没有，拷贝自由。


#include "DataAsset_StartUpDataBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorASC,
                                                              int32 InApplyLevel) const
{
	check(InWarriorASC);
	GrantAbilities(ActivateOnGivenAbilities, InWarriorASC, InApplyLevel);
	GrantAbilities(ReactiveAbilities, InWarriorASC, InApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilities,
                                                UWarriorAbilitySystemComponent* InWarriorASC, int32 InApplyLevel) const
{
	check(InWarriorASC);

	for (const auto& AbilityClass : InAbilities)
	{
		if (!AbilityClass) continue;

		FGameplayAbilitySpec AbilitySpec{AbilityClass, InApplyLevel};
		AbilitySpec.SourceObject = InWarriorASC->GetAvatarActor();
		InWarriorASC->GiveAbility(AbilitySpec);
	}
}
