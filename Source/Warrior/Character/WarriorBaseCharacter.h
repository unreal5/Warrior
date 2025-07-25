// 版权没有，拷贝自由。

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Interface/PawnCombatInterface.h"
#include "WarriorBaseCharacter.generated.h"

class UDataAsset_StartUpDataBase;
class UWarriorAttributeSet;
class UWarriorAbilitySystemComponent;

UCLASS(Abstract)
class WARRIOR_API AWarriorBaseCharacter : public ACharacter, public IAbilitySystemInterface, public IPawnCombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarriorBaseCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = AbilitySystem)
	UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = AbilitySystem)
	UWarriorAttributeSet* WarriorAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character | Data")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;
public:
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const
	{
		return WarriorAbilitySystemComponent;
	}

	FORCEINLINE UWarriorAttributeSet* GetWarriorAttribute() const { return WarriorAttributeSet; }
	
};
