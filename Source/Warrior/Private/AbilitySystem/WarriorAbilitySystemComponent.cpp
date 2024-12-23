// 高级动作RPG游戏


#include "AbilitySystem/WarriorAbilitySystemComponent.h"

#include "WarriorType/WarriorStructTypes.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) return;

	for (const auto& AbilitySpec : GetActivatableAbilities())
	{
		//if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InInputTag)) continue;
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}

void UWarriorAbilitySystemComponent::GrantHeroWeaponAbilities(
	const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel,
	TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles)
{
	if (InDefaultWeaponAbilities.IsEmpty()) return;

	for (const auto& AbilitySet : InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant, ApplyLevel);
		AbilitySpec.SourceObject = GetAvatarActor();

		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);
		auto AbilitySpecHandle = GiveAbility(AbilitySpec);
		OutGrantedAbilitySpecHandles.AddUnique(AbilitySpecHandle);
	}
}

void UWarriorAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(
	TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandles)
{
	for (const auto& SpecHandle : InGrantedAbilitySpecHandles)
	{
		if (SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}
	InGrantedAbilitySpecHandles.Empty();
}
