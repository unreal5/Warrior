// 版权没有，拷贝自由。


#include "WarriorAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "WarriorDebugHelper.h"

UWarriorAttributeSet::UWarriorAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UWarriorAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth =FMath::Clamp(GetCurrentHealth(),0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);
	}

	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());
		SetCurrentRage(NewCurrentRage);
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float NewCurrentHealth = GetCurrentHealth() - GetDamageTaken();
		SetCurrentHealth(FMath::Clamp(NewCurrentHealth, 0.f, GetMaxHealth()));

		//TODO: Notify UI
		//处理死亡
		const FString DebugString = FString::Printf(TEXT("生命值: %f, 伤害值: %f"), GetCurrentHealth(), GetDamageTaken());
		Debug::Print(DebugString, FColor::Red);
	}
}
