// 版权没有，拷贝自由。


#include "WarriorWeaponBase.h"

#include "Components/BoxComponent.h"


// Sets default values
AWarriorWeaponBase::AWarriorWeaponBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);
	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	// 根据需要启用
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
