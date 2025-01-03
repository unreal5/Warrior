// 高级动作RPG游戏


#include "WarriorFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"

UWarriorAbilitySystemComponent* UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor* InActor)
{
	return Cast<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, const FGameplayTag& InTagToAdd)
{
	auto ASC = NativeGetWarriorASCFromActor(InActor);
	if (!ASC) return;
	if (!ASC->HasMatchingGameplayTag(InTagToAdd))
	{
		ASC->AddLooseGameplayTag(InTagToAdd);
	}
}

void UWarriorFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, const FGameplayTag& InTagToRemove)
{
	auto ASC = NativeGetWarriorASCFromActor(InActor);
	if (!ASC) return;
	if (ASC->HasMatchingGameplayTag(InTagToRemove))
	{
		ASC->RemoveLooseGameplayTag(InTagToRemove);
	}
}
bool UWarriorFunctionLibrary::NativeDoesActorhaveTag(AActor* InActor, const FGameplayTag& InTagToCheck)
{
	if (const auto Asc = NativeGetWarriorASCFromActor(InActor))
	{
		return Asc->HasMatchingGameplayTag(InTagToCheck);
	}
	return false;
}

void UWarriorFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, const FGameplayTag& InTagToCheck,
	EWarriorConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorhaveTag(InActor, InTagToCheck) ? EWarriorConfirmType::Yes : EWarriorConfirmType::No;
}
