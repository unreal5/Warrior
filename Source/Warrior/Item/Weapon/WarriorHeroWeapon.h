// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "WarriorWeaponBase.h"
#include "WarriorType/WarriorStructTypes.h"
#include "WarriorHeroWeapon.generated.h"

UCLASS()
class WARRIOR_API AWarriorHeroWeapon : public AWarriorWeaponBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FWarriorHeroWeaponData HeroWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintPure)
	const TArray<FGameplayAbilitySpecHandle>& GetGrantedAbilitySpecHandles() const;
private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
