// 版权没有，拷贝自由。


#include "WarriorHeroLinkedAnimLayer.h"

#include "WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	USkeletalMeshComponent* OwningComp = GetOwningComponent();
	if (!OwningComp) return nullptr;

	return Cast<UWarriorHeroAnimInstance>(OwningComp->GetAnimInstance());
}
