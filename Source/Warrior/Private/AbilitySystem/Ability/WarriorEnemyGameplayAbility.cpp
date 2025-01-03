// 高级动作RPG游戏


#include "AbilitySystem/Ability/WarriorEnemyGameplayAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Character/WarriorEnemyCharacter.h"

AWarriorEnemyCharacter* UWarriorEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (CachedWarriorEnemyCharacter.IsValid()) return CachedWarriorEnemyCharacter.Get();

	if (auto ActorInfo = GetCurrentActorInfo())
	{
		CachedWarriorEnemyCharacter = Cast<AWarriorEnemyCharacter>(ActorInfo->AvatarActor);
	}
	return CachedWarriorEnemyCharacter.Get();
}

UEnemyCombatComponent* UWarriorEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	if (auto EnemyCharacter = GetEnemyCharacterFromActorInfo())
	{
		return EnemyCharacter->GetEnemyCombatComponent();
	}
	return nullptr;
}
