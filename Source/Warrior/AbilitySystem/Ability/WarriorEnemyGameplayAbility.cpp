// 版权没有，拷贝自由。


#include "WarriorEnemyGameplayAbility.h"

#include "Character/WarriorEnemyCharacter.h"

AWarriorEnemyCharacter* UWarriorEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedWarriorEnemyCharacter.IsValid())
	{
		CachedWarriorEnemyCharacter = Cast<AWarriorEnemyCharacter>(GetAvatarActorFromActorInfo());
	}
	return CachedWarriorEnemyCharacter.Get();
}

UEnemyCombatComponent* UWarriorEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	AWarriorEnemyCharacter* EnemyCharacter = GetEnemyCharacterFromActorInfo();
	if (!EnemyCharacter) return nullptr;

	return EnemyCharacter->GetEnemyCombatComponent();
}
