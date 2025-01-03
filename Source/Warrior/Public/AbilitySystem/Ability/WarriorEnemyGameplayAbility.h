// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"
#include "WarriorEnemyGameplayAbility.generated.h"


class UEnemyCombatComponent;
class AWarriorEnemyCharacter;

UCLASS()
class WARRIOR_API UWarriorEnemyGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Warrior | EnemyGameplayAbility")
	AWarriorEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior | EnemyGameplayAbility")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();
private:
	TWeakObjectPtr<AWarriorEnemyCharacter> CachedWarriorEnemyCharacter;
	
};
