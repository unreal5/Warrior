// 版权没有，拷贝自由。


#include "PawnCombatComponent.h"

#include "WarriorDebugHelper.h"
#include "Components/BoxComponent.h"
#include "Item/Weapon/WarriorWeaponBase.h"

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

void UPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
	if (ToggleDamageType == EToggleDamageType::CurrentEquippedWeapon)
	{
		if (auto* EquippedWeapon = GetCurrentCharacterEquippedWeapon())
		{
			const auto CollisionState = bShouldEnable ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision;
			EquippedWeapon->GetWeaponCollisionBox()->SetCollisionEnabled(CollisionState);
		}

		// Debug log
		FString CollisionStateStr = bShouldEnable ? TEXT("Enabled") : TEXT("Disabled");
		Debug::Print(CollisionStateStr);
	}
}
