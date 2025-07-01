#pragma once
#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogWarrior, Log, All);

namespace Debug
{
	static void Print(const FString& Message, const FColor& Color = FColor::MakeRandomColor(), int32 InKey = -1, float Duration = 5.0f)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(InKey, Duration, Color, Message);
		}
		UE_LOG(LogWarrior, Warning, TEXT("%s"), *Message);
	}
}
