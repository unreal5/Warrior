// 高级动作RPG游戏


#include "Character/WarriorEnemyCharacter.h"

#include "Component/Combat/EnemyCombatComponent.h"
#include "DataAsset/StartupData/DataAsset_StartupDataBase.h"
#include "Engine/AssetManager.h"
#include "GameFramework/CharacterMovementComponent.h"

AWarriorEnemyCharacter::AWarriorEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 180.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1024.0f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("CombatComponent"));
}

void AWarriorEnemyCharacter::InitEnemyStartUpData()
{
	if (CharacterStartupData.IsNull()) return;

	UAssetManager::GetStreamableManager().RequestAsyncLoad(CharacterStartupData.ToSoftObjectPath(),
	                                                       FStreamableDelegate::CreateLambda(
		                                                       [this]()
		                                                       {
			                                                       if (auto LoadedData = CharacterStartupData.Get())
			                                                       {
			                                                       	LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);
			                                                       }
		                                                       }
	                                                       ));
}

void AWarriorEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitEnemyStartUpData();
}
