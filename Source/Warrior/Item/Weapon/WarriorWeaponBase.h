// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WarriorWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class WARRIOR_API AWarriorWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWarriorWeaponBase();

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Weapons")
	UStaticMeshComponent* WeaponMesh;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Weapons")
	UBoxComponent* WeaponCollisionBox;

public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox; }
};
