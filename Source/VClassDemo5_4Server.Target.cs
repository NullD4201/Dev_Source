// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class VClassDemo5_4ServerTarget : TargetRules
{
	public VClassDemo5_4ServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
        //ExtraModuleNames.Add("VClassDemo5_4");
        ExtraModuleNames.AddRange(new string[] { "VClassDemo5_4" });
    }
}
