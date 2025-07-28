// 版权没有，拷贝自由。


#include "HeroCombatComponent.h"

#include "WarriorDebugHelper.h"
#include "Item/Weapon/WarriorHeroWeapon.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(const FGameplayTag& InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	Debug::Print(GetOwningPawn()->GetName() + TEXT("击中") + HitActor->GetName(), FColor::Red, 1);
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	Debug::Print(GetOwningPawn()->GetName()+TEXT("从") + InteractedActor->GetName() + TEXT("拔出武器"), FColor::Green, 2);
}
