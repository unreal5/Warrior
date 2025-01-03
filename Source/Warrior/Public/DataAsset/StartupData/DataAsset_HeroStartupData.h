// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/StartupData/DataAsset_StartupDataBase.h"
#include "WarriorType/WarriorStructTypes.h"
#include "DataAsset_HeroStartupData.generated.h"


UCLASS()
class WARRIOR_API UDataAsset_HeroStartupData : public UDataAsset_StartupDataBase
{
	GENERATED_BODY()

public:
	virtual void
	GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category="StartupData", meta=(TitleProperty = "InputTag"))
	TArray<FWarriorHeroAbilitySet> HeroStartupAbilitySets;
};
