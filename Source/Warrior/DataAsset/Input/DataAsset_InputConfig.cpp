// 版权没有，拷贝自由。


#include "DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	auto Element = NativeInputAction.FindByPredicate([&InInputTag](const FWarriorInputActionConfig& InputConfig)
	{
		return (InInputTag.MatchesTagExact(InputConfig.InputTag) && InputConfig.InputAction != nullptr);
	});
	return Element ? Element->InputAction : nullptr;
}
