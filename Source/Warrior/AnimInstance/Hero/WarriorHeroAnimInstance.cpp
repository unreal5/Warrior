// 版权没有，拷贝自由。


#include "WarriorHeroAnimInstance.h"

#include "Character/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
	}
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelax = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelax = IdleElapsedTime >= EnterRelaxStateThreshold;
	}
	
}
