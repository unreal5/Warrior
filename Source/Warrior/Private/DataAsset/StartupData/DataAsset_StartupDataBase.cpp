// 高级动作RPG游戏


#include "DataAsset/StartupData/DataAsset_StartupDataBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"

void UDataAsset_StartupDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive,
                                                              int32 ApplyLevel)
{
	check(InASCToGive);
	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);

	for (const auto& GameplayEffectClass : StartupGameplayEffects)
	{
		if (!GameplayEffectClass) continue;
		
		auto EffectContext = InASCToGive->MakeEffectContext();
		EffectContext.AddSourceObject(InASCToGive->GetAvatarActor());
		FGameplayEffectSpecHandle SpecHandle = InASCToGive->MakeOutgoingSpec(
			GameplayEffectClass, ApplyLevel, EffectContext);
		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle ActiveGEHandle = InASCToGive->ApplyGameplayEffectSpecToSelf(
				*SpecHandle.Data.Get());
		}
	}
}

void UDataAsset_StartupDataBase::GrantAbilities(TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
                                                UWarriorAbilitySystemComponent* InAscToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) return;

	for (const auto& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability, ApplyLevel);
		AbilitySpec.SourceObject = InAscToGive->GetAvatarActor();

		InAscToGive->GiveAbility(AbilitySpec);
	}
}
