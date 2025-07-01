// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Warrior : ModuleRules
{
	public Warrior(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"GameplayTags",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[]
		{
			"Warrior"
		});
	}
}