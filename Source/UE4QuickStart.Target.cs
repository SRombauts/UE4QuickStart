// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sébastien Rombauts - distributed under the MIT License

using UnrealBuildTool;
using System.Collections.Generic;

public class UE4QuickStartTarget : TargetRules
{
	public UE4QuickStartTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "UE4QuickStart" } );
	}
}
