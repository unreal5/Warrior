// 版权没有，拷贝自由。


#include "GEExecCalc_DamageTaken.h"

#include "WarriorDebugHelper.h"
#include "WarriorGameplayTags.h"
#include "AbilitySystem/WarriorAttributeSet.h"

struct FWarriorDamageCapture
{
	FWarriorDamageCapture();
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)
};

static const FWarriorDamageCapture& GetWarriorDamageCapture()
{
	static FWarriorDamageCapture WarriorDamageCapture;
	return WarriorDamageCapture;
}

UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DamageTakenDef);
}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
                                                     FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();
	//const FGameplayEffectContextHandle EffectContext = EffectSpec.GetContext();

	FAggregatorEvaluateParameters EvalParams;
	EvalParams.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvalParams.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetWarriorDamageCapture().AttackPowerDef, EvalParams,
	                                                           SourceAttackPower);

	// 计算在GE中设置的一些属性
	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;
	for (const auto& [Tag, Value] : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (Tag.MatchesTagExact(WarriorGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = Value;
		}
		if (Tag.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = Value;
		}
		if (Tag.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = Value;
		}
	}

	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetWarriorDamageCapture().DefensePowerDef, EvalParams,
	                                                           TargetDefensePower);

	if (UsedLightAttackComboCount > 0)
	{
		const float DamageIncreasePerLight = (UsedLightAttackComboCount - 1) * 0.05f + 1.f; // 每次轻攻击增加5%的伤害
		BaseDamage *= DamageIncreasePerLight;
	}
	if (UsedHeavyAttackComboCount > 0)
	{
		const float DamageIncreasePerHeavy = UsedHeavyAttackComboCount * 0.15f + 1.f; // 每次重攻击增加15%的伤害
		BaseDamage *= DamageIncreasePerHeavy;
	}
	const float FinalDamageDone = BaseDamage * SourceAttackPower / TargetDefensePower;
	if (FinalDamageDone > 0.f)
	{
		FGameplayModifierEvaluatedData DamageTakenModifier(
			GetWarriorDamageCapture().DamageTakenProperty, EGameplayModOp::Override, FinalDamageDone);
		OutExecutionOutput.AddOutputModifier(DamageTakenModifier);
	}

	/*
	Debug::Print(TEXT("SourceAttackPower"), SourceAttackPower, 0, FColor::Green);
	Debug::Print(TEXT("TargetDefensePower"), TargetDefensePower, 1, FColor::Red);
	Debug::Print(TEXT("BaseDamage"), BaseDamage, 2, FColor::Blue);
	Debug::Print(TEXT("UsedLightAttackComboCount"), UsedLightAttackComboCount, 3, FColor::Yellow);
	Debug::Print(TEXT("UsedHeavyAttackComboCount"), UsedHeavyAttackComboCount, 4, FColor::Cyan);
	Debug::Print(TEXT("FinalDamageDone"), FinalDamageDone, 5, FColor::Magenta);
	*/	
}

FWarriorDamageCapture::FWarriorDamageCapture()
{
	DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, AttackPower, Source, false)
	DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DefensePower, Target, false)
	DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DamageTaken, Target, false)
}
