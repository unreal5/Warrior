// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "DataAsset_EnemyStartUpData.generated.h"

class UWarriorEnemyGameplayAbility;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_EnemyStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void
	GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASC, int32 InApplyLevel = 1) const override;

private:
	UPROPERTY(EditDefaultsOnly, Category="StartUp|Data")
	TArray<TSubclassOf<UWarriorEnemyGameplayAbility>> EnemyCombatAbilities;
};
