// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "WarriorType/WarriorStructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"
class UWarriorGameplayAbility;



UCLASS()
class WARRIOR_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void
	GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASC, int32 InApplyLevel = 1) const override;

private:
	UPROPERTY(EditDefaultsOnly, Category="StartUp|Data", meta=(TitleProperty="InputTag"))
	TArray<FWarriorHeroAbilitySet> HeroStartUpAbilitySets;
};
