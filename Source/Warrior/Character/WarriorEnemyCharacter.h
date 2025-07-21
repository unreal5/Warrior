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
	AWarriorEnemyCharacter();
	virtual void PossessedBy(AController* NewController) override;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Combat)
	UEnemyCombatComponent* EnemyCombatComponent;
private:
	void InitEnemyStartUpData();
public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
	
};
