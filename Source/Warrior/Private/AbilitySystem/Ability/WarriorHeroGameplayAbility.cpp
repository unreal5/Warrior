// 版权没有，拷贝自由。


#include "AbilitySystem/Ability/WarriorHeroGameplayAbility.h"

#include "Character/WarriorHeroCharacter.h"
#include "Controller/WarriorHeroController.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor.Get());
	}

	return CachedWarriorHeroCharacter.Get();
}

AWarriorHeroController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<AWarriorHeroController>(CurrentActorInfo->PlayerController.Get());
	}
	return CachedWarriorHeroController.Get();
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	if(auto Hero = GetHeroCharacterFromActorInfo())
	{
		return Hero->GetHeroCombatComponent();
	}
	return nullptr;
}
