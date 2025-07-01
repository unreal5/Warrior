// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WarriorBaseGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AWarriorBaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	AWarriorBaseGameMode();
};
