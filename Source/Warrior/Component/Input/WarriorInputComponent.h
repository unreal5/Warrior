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
