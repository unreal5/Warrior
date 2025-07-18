// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyCombatComponent;

UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorEnemyCharacter();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Combat)
	UEnemyCombatComponent* EnemyCombatComponent;
public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
};
