#Must be the first statement in your script
Param(
		[String]$buildType=$Debug,
		[String]$build=$x64
	)

$scriptPath = split-path -parent $MyInvocation.MyCommand.Definition
$sourcePath = "$scriptPath\.."

################################################################################
###   FUNCTION: CreateBuildPath   ##############################################
################################################################################

function CreateBuildPath
{
	cd "$sourcePath"

	If (!(Test-Path -path "$sourcePath\BUILD")) {
		mkdir .\BUILD
		echo ""
	}

	cd .\BUILD

	If (!(Test-Path -path "$sourcePath\BUILD\$build")) {
		mkdir "$sourcePath\BUILD\$build"
		echo ""
	}

	cd "$sourcePath\BUILD\$build"
}


CreateBuildPath

cmake -G "Visual Studio 14 2015 Win64" ..
cmake --build . --use-stderr --config $buildType

cd $scriptPath
