cmake_minimum_required(VERSION 3.2)
project(CursesDungeon)

if(NOT WIN32)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

file(GLOB SOURCE_MAIN_HEADERS Src/*.hpp)
file(GLOB SOURCE_MAIN Src/*.cpp)

add_executable(CursesDungeon
					${SOURCE_MAIN_HEADERS}
					${SOURCE_MAIN}
				)

add_custom_command(TARGET CursesDungeon POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${CMAKE_CURRENT_SOURCE_DIR}/Control/Assets/"
			$<TARGET_FILE_DIR:CursesDungeon>
		VERBATIM
		)

if(WIN32)
	add_custom_command(TARGET CursesDungeon POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_directory
				"${CMAKE_CURRENT_SOURCE_DIR}/Control/Assets/"
				"$<TARGET_FILE_DIR:CursesDungeon>/.."
			VERBATIM
			)
endif()
