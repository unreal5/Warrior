// 高级动作RPG游戏


#include "AnimInstance/Hero/WarriorHeroLinkedAnimLayer.h"

#include "AnimInstance/Hero/WarriorHeroAnimInstance.h"

class UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
