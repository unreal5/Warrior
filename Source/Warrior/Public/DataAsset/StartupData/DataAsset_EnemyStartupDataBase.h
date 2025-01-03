// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartupData/DataAsset_StartupDataBase.h"
#include "DataAsset_EnemyStartupDataBase.generated.h"

class UWarriorEnemyGameplayAbility;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_EnemyStartupDataBase : public UDataAsset_StartupDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category="StartupData", meta=(TitleProperty = "InputTag"))
	TArray<TSubclassOf<UWarriorEnemyGameplayAbility>> EnemyCombatAbilities;
};
