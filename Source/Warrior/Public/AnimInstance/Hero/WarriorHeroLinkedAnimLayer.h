// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/WarriorBaseAnimInstance.h"
#include "WarriorHeroLinkedAnimLayer.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroLinkedAnimLayer : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Warrior|AnimInstance", meta = (BlueprintThreadSafe))
	class UWarriorHeroAnimInstance* GetHeroAnimInstance() const;
};
