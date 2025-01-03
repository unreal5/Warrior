// 高级动作RPG游戏


#include "DataAsset/StartupData/DataAsset_EnemyStartupDataBase.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Ability/WarriorEnemyGameplayAbility.h"

void UDataAsset_EnemyStartupDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (auto AbilityClass : EnemyCombatAbilities)
	{
		if (!IsValid(AbilityClass)) continue;
		
		FGameplayAbilitySpec GameplayAbilitySpec = FGameplayAbilitySpec(AbilityClass, ApplyLevel);
		GameplayAbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		InASCToGive->GiveAbility(GameplayAbilitySpec);
	}
}
