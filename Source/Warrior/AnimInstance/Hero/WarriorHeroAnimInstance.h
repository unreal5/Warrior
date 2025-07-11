// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/WarriorCharacterAnimInstance.h"
#include "WarriorHeroAnimInstance.generated.h"

class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | Reference")
	AWarriorHeroCharacter* OwningHeroCharacter;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | Locomotion")
	bool bShouldEnterRelax = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData | Locomotion")
	float EnterRelaxStateThreshold = 5.f; // 进入放松状态的阈值

	float IdleElapsedTime = 0.f;
};
