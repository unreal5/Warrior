// 版权没有，拷贝自由。


#include "WarriorCharacterAnimInstance.h"

#include "Character/WarriorBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// NativeInitializeAnimation 在编辑器运动时也会被调用， 此时 OwningActor 为 nullptr。
void UWarriorCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AWarriorBaseCharacter>(GetOwningActor());
	if (!OwningCharacter) return;
	OwningMovementComponent = OwningCharacter->GetCharacterMovement();
}


void UWarriorCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent)
		return;

	GroundSpeed = OwningMovementComponent->Velocity.Size2D();
	bHasAcceleration = !OwningMovementComponent->GetCurrentAcceleration().IsNearlyZero();
}
