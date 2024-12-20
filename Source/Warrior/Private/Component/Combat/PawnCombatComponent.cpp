// 高级动作RPG游戏


#include "Component/Combat/PawnCombatComponent.h"

#include "Item/Weapon/WarriorWeaponBase.h"

void UPawnCombatComponent::RegisterSpawnWeapon(FGameplayTag InWeaponTagToRegister,
                                               AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	check(IsValid(InWeaponToRegister));
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister),
	       TEXT("Weapon with tag %s already exists in the character carried weapon map."),
	       *InWeaponTagToRegister.ToString());
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);
	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		return *CharacterCarriedWeaponMap.Find(InWeaponTagToGet);
	}
	return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid()) return nullptr;

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
