// UE4 C++ Quick Start Tutorials - copyright 2015-2020 Sebastien Rombauts - distributed under the MIT License

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4QuickStartTarget : TargetRules
{
	public UE4QuickStartTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "UE4QuickStart" } );
	}
}
