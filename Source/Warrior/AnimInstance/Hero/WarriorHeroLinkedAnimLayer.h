// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/WarriorBaseAnimInstance.h"
#include "WarriorHeroLinkedAnimLayer.generated.h"

class UWarriorHeroAnimInstance;

UCLASS()
class WARRIOR_API UWarriorHeroLinkedAnimLayer : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
	UWarriorHeroAnimInstance* GetHeroAnimInstance() const;
};
