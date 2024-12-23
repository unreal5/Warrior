// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class AWarriorHeroController;
class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "Warrior | Ability")
	AWarriorHeroCharacter* GetHeroCharacterFromCharacterInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior | Ability")
	AWarriorHeroController* GetHeroControllerFromCharacterInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior | Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
private:
	TWeakObjectPtr<AWarriorHeroCharacter> CachedWarriorHeroCharacter;
	TWeakObjectPtr<AWarriorHeroController> CachedWarriorHeroController;
};
