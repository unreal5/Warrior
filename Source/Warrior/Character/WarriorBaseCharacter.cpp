// 版权没有，拷贝自由。


#include "WarriorBaseCharacter.h"


// Sets default values
AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	// 对于角色类，不需要Tick
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// 一些VFX会投射贴花，角色不需要
	GetMesh()->SetReceivesDecals(false);
}