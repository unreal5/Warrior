// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarriorType/WarriorEnumTypes.h"
#include "WarriorFunctionLibrary.generated.h"

class UPawnCombatComponent;


class UWarriorAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UWarriorAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag InTagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag InTagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag InTagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary",
		meta=(DisplayName = "Does Actor Has Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHasTag(AActor* InActor, FGameplayTag InTagToCheck, EWarriorConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);
	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary",
		meta=(DisplayName = "GetPawnCombatComponentFromActor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, EWarriorValidType& OutValidType);
};
