// 高级动作RPG游戏

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/WarriorBaseAnimInstance.h"
#include "WarriorCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorCharacterAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
protected:
	UPROPERTY()
	class AWarriorBaseCharacter* OwningCharacter;

	UPROPERTY()
	class UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocomotionData")
	bool bHasAcceleration;
};
