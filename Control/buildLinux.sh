#!/bin/bash
ScripDir=$(dirname $(readlink -f $0))
cd "${ScripDir}/.."
echo "${ScripDir}/.."

build="x64"
buildType="Debug"
for i in "$@"
do
	case "$i" in
		-64)
			$build="x64"
			;;
		-32)
			$build="x32"
			;;

		-R|Release)
			$buildType="Release"
			;;

		-D|Debug)
			$buildType="Debug"
			;;

		*)
			echo "what the hack?"		# unknown option
		;;
	esac
done

if [[ ! -d "BUILD" ]]; then
	mkdir BUILD
	echo "=== BUILD folder created! ==="
fi

cd BUILD/

if [[ ! -d "$build" ]]; then
	mkdir $build
	echo "=== $build folder created! ==="
fi

cd $build

cmake ../..
cmake --build . --use-stderr --config $buildType
