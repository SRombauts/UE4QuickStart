// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4QuickStartEditorTarget : TargetRules
{
	public UE4QuickStartEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "UE4QuickStart" } );
	}
}
