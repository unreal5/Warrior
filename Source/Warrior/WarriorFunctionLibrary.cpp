// 版权没有，拷贝自由。


#include "WarriorFunctionLibrary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Component/Combat/PawnCombatComponent.h"
#include "Interface/PawnCombatInterface.h"

UWarriorAbilitySystemComponent* UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor* InActor)
{
	return Cast<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag InTagToAdd)
{
	auto ASC = NativeGetWarriorASCFromActor(InActor);
	if (nullptr == ASC) return;

	if (!ASC->HasMatchingGameplayTag(InTagToAdd))
	{
		ASC->AddLooseGameplayTag(InTagToAdd);
	}
}

void UWarriorFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag InTagToRemove)
{
	auto ASC = NativeGetWarriorASCFromActor(InActor);
	if (nullptr == ASC) return;
	if (ASC->HasMatchingGameplayTag(InTagToRemove))
	{
		ASC->RemoveLooseGameplayTag(InTagToRemove);
	}
}

bool UWarriorFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag InTagToCheck)
{
	auto ASC = NativeGetWarriorASCFromActor(InActor);
	return ASC ? ASC->HasMatchingGameplayTag(InTagToCheck) : false;
}

void UWarriorFunctionLibrary::BP_DoesActorHasTag(AActor* InActor, FGameplayTag InTagToCheck,
                                                 EWarriorConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, InTagToCheck) ? EWarriorConfirmType::Yes : EWarriorConfirmType::No;
}

UPawnCombatComponent* UWarriorFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor);
	if (auto PawnCombatInterface = Cast<IPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}
	return nullptr;
}

UPawnCombatComponent* UWarriorFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor,
	EWarriorValidType& OutValidType)
{
	OutValidType = EWarriorValidType::Invalid;
	if (auto PawnCombatComponent = NativeGetPawnCombatComponentFromActor(InActor))
	{
		OutValidType = EWarriorValidType::Valid;
		return PawnCombatComponent;
	}
	return nullptr;
}


