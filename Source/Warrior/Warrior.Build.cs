// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Warrior : ModuleRules
{
	public Warrior(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks" });

		//PublicIncludePaths.AddRange(new string[] { "Warrior/Public" });
	}
}