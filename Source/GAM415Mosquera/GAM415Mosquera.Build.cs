// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAM415Mosquera : ModuleRules
{
	public GAM415Mosquera(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "Niagara" });
	}
}
