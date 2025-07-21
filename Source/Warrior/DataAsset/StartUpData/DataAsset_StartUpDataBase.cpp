// 版权没有，拷贝自由。


#include "DataAsset_StartUpDataBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASC,
                                                              int32 InApplyLevel) const
{
	check(InASC);
	
	GrantAbilities(ActivateOnGivenAbilities, InASC, InApplyLevel);
	GrantAbilities(ReactiveAbilities, InASC, InApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilities,
                                                UWarriorAbilitySystemComponent* InASC, int32 InApplyLevel) const
{
	check(InASC);

	for (const auto& AbilityClass : InAbilities)
	{
		if (!AbilityClass) continue;

		FGameplayAbilitySpec AbilitySpec{AbilityClass, InApplyLevel};
		AbilitySpec.SourceObject = InASC->GetAvatarActor();
		InASC->GiveAbility(AbilitySpec);
	}
}
