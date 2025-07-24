// 版权没有，拷贝自由。


#include "DataAsset_StartUpDataBase.h"

#include "WarriorDebugHelper.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASC,
                                                              int32 InApplyLevel) const
{
	check(InASC);
	
	GrantAbilities(ActivateOnGivenAbilities, InASC, InApplyLevel);
	GrantAbilities(ReactiveAbilities, InASC, InApplyLevel);

	for (const auto& EffectClass : StartUpGameplayEffects)
	{
		if (!EffectClass) continue;

		FGameplayEffectContextHandle EffectContextHandle = InASC->MakeEffectContext();
		EffectContextHandle.AddSourceObject(InASC->GetAvatarActor());
		EffectContextHandle.AddInstigator(InASC->GetAvatarActor(), InASC->GetAvatarActor());
		FGameplayEffectSpecHandle EffectSpecHandle = InASC->MakeOutgoingSpec(EffectClass, InApplyLevel, EffectContextHandle);
		if (EffectSpecHandle.IsValid())
		{
			InASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data);
		}
		else
		{
			UE_LOG(LogWarrior, Error, TEXT("Failed to create GameplayEffectSpec for %s"), *EffectClass->GetName());
		}

	}
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
