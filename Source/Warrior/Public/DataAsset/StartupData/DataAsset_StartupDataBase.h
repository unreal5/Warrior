// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDataBase.generated.h"

class UGameplayEffect;
class UWarriorAbilitySystemComponent;
class UWarriorGameplayAbility;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartupDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ReactiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UGameplayEffect>> StartupGameplayEffects;
	
	void GrantAbilities(TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
	                    UWarriorAbilitySystemComponent* InAscToGive, int32 ApplyLevel);
};
