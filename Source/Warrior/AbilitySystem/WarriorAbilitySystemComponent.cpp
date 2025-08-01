// 版权没有，拷贝自由。


#include "WarriorAbilitySystemComponent.h"

#include "Ability/WarriorGameplayAbility.h"
#include "WarriorType/WarriorStructTypes.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (const auto& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag)) continue;
		if (AbilitySpec.IsActive())
		{
			// 如果技能已经激活，则不再重复激活
			continue;
		}
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InputTag)
{
}

void UWarriorAbilitySystemComponent::GrantHeroWeaponAbilities(
	const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel,
	TArray<FGameplayAbilitySpecHandle>& OutGrantAbilitySpecHandles)
{
	for (const auto& AbilitySet : InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec((AbilitySet.AbilityToGrant));

		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

		auto SpecHandle = GiveAbility(AbilitySpec);
		// store the handle for later use
		OutGrantAbilitySpecHandles.AddUnique(SpecHandle);
	}
}

void UWarriorAbilitySystemComponent::RemoveGrantedAbilitySpecHandles(
	TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove)
{
	for (const auto& SpecHandle : InSpecHandlesToRemove)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}
	InSpecHandlesToRemove.Empty();
}
