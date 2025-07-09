// 版权没有，拷贝自由。


#include "WarriorHeroGameplayAbility.h"

#include "Character/WarriorHeroCharacter.h"
#include "PlayerController/WarriorHeroController.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(GetAvatarActorFromActorInfo());
	}
	return CachedWarriorHeroCharacter.Get();
}

AWarriorHeroController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<AWarriorHeroController>(GetActorInfo().PlayerController);
	}
	return CachedWarriorHeroController.Get();
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
