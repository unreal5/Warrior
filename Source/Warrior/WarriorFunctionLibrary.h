// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarriorFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum class EWarriorConfirmType : uint8
{
	Yes UMETA(DisplayName = "Yes"),
	No UMETA(DisplayName = "No"),
};

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
};
