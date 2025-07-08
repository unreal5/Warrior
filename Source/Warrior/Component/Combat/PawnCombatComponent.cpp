// 版权没有，拷贝自由。


#include "PawnCombatComponent.h"

#include "WarriorDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTag, AWarriorWeaponBase* InWeapon,
                                                 bool bReigsterAsEquippedWeapon)
{
	check(InWeapon);
	if (!InWeapon)
	{
		UE_LOG(LogWarrior, Error, TEXT("UPawnCombatComponent::RegisterSpawnedWeapon: InWeapon is null!"));
		return;
	}

	const auto bFound = CharacterCarriedWeapons.Contains(InWeaponTag);
	checkf(!bFound, TEXT("UPawnCombatComponent::RegisterSpawnedWeapon: Weapon with tag %s already exists!"),
	       *InWeaponTag.ToString());

	if (bFound) return;

	CharacterCarriedWeapons.Emplace(InWeaponTag, InWeapon);

	if (bReigsterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTag;
	}
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	auto FoundWeapon = CharacterCarriedWeapons.Find(InWeaponTag);
	return nullptr != FoundWeapon ? *FoundWeapon : nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCurrentCharacterEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid()) return nullptr;

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
