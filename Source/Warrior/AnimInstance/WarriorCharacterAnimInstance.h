// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseAnimInstance.h"
#include "WarriorCharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class AWarriorBaseCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorCharacterAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	// 运动于Worker线程，而不是Game线程。
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(Transient)
	AWarriorBaseCharacter* OwningCharacter;
	UPROPERTY(Transient)
	UCharacterMovementComponent* OwningMovementComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | Locomotion")
	float GroundSpeed;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | Locomotion")
	bool bHasAcceleration;
};
