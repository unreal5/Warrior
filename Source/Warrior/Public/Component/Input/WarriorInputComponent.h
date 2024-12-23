// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAsset/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <typename UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,
	                           ETriggerEvent InTriggerEvent, UserObject* InUserObject, CallbackFunc InCallbackFunc);

	template <typename UserObject, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* InContexObject,
	                            CallbackFunc InputPressedFunc, CallbackFunc InputReleasedFunc);
};

template <typename UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                   const FGameplayTag& InInputTag, ETriggerEvent InTriggerEvent,
                                                   UserObject* InUserObject, CallbackFunc InCallbackFunc)
{
	check(InInputConfig);
	check(InUserObject);

	if (auto FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, InTriggerEvent, InUserObject, InCallbackFunc);
	}
}

template <typename UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig,
                                                    UserObject* InContexObject, CallbackFunc InputPressedFunc,
                                                    CallbackFunc InputReleasedFunc)
{
	check(InInputConfig);
	check(InContexObject);

	for (const auto& AbilityInputActionConfig : InInputConfig->AbilityInputActions)
	{
		if (!AbilityInputActionConfig.IsValid()) continue;

		auto action = AbilityInputActionConfig.InputAction;
		const auto& Tag = AbilityInputActionConfig.InputTag;
		BindAction(action, ETriggerEvent::Started, InContexObject, InputPressedFunc, Tag);
		BindAction(action, ETriggerEvent::Completed, InContexObject, InputReleasedFunc, Tag);
	}
}
