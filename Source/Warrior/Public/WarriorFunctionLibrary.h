// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarriorFunctionLibrary.generated.h"

class UWarriorAbilitySystemComponent;

UENUM()
enum class EWarriorConfirmType : uint8
{
	Yes,
	No,
};

UCLASS()
class WARRIOR_API UWarriorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UWarriorAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, const FGameplayTag& InTagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, const FGameplayTag& InTagToRemove);

	static bool NativeDoesActorhaveTag(AActor* InActor, const FGameplayTag& InTagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Warrior | FunctionLibrary",
		meta=(DisplayName = "DoesActorHaveTag", ExpandEnumAsExecs="OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, const FGameplayTag& InTagToCheck,
	                                EWarriorConfirmType& OutConfirmType);
};
