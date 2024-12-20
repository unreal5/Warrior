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
