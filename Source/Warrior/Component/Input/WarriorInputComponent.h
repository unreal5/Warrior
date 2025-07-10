// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAsset/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	UWarriorInputComponent();

	template <typename UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,
	                           ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Callback);

	template <typename UserObject, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject,
	                            CallbackFunc InputPressedFunc, CallbackFunc InputReleasedFunc);
};


template <typename UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                   const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent,
                                                   UserObject* ContextObject, CallbackFunc Callback)
{
	check(InInputConfig);

	UInputAction* Action = InInputConfig->FindNativeInputActionByTag(InInputTag);
	if (!Action) return;

	BindAction(Action, TriggerEvent, ContextObject, Callback);
}

template <typename UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                    UserObject* ContextObject, CallbackFunc InputPressedFunc,
                                                    CallbackFunc InputReleasedFunc)
{
	check(InInputConfig);

	for (const auto& AbilityInputAction : InInputConfig->AbilityInputAction)
	{
		if (!AbilityInputAction.IsValid()) continue;
		BindAction(AbilityInputAction.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc,
		           AbilityInputAction.InputTag);
		BindAction(AbilityInputAction.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedFunc,
		           AbilityInputAction.InputTag);
	}
}
