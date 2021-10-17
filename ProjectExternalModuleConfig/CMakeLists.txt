# @Author: Lloyd Thomas
# @Date: 17/10/2021


# CMake Version
cmake_minimum_required(VERSION 3.8
)


# Title of Module
project("ProjectExternalModuleConfig"
)


# GLFW Graphic Lib Configurations
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE
)

set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE
)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE
)


# Location of GLFW & Glew
add_subdirectory(glfw/glfw-3.3.3/glfw-3.3.3/
	glew-2.1.0-win32/glew-2.1.0/
)


# Find OpenGL Lib
find_package(OpenGL REQUIRED
)


# Src Files (.cpp and .h)
add_executable(ProjectExternalModuleConfig
	# Externals 
	"glew-2.1.0-win32/glew-2.1.0/include/GL/eglew.h" 
	"glew-2.1.0-win32/glew-2.1.0/include/GL/glew.h" 
	"glew-2.1.0-win32/glew-2.1.0/include/GL/glxew.h" 
	"glew-2.1.0-win32/glew-2.1.0/include/GL/wglew.h"

	# Main testing class
	"ProjectExternalModuleConfig.cpp" "ProjectExternalModuleConfig.h"
	
	# Modules
	"Modules/PlayerHUDTest.cpp" "Modules/PlayerHUDTest.h"

	# Main src file
	"Main.cpp"
)


# Include dirs
target_include_directories(ProjectExternalModuleConfig
	PUBLIC glfw/include
	PUBLIC OpenGL::GL
	PUBLIC glew-2.1.0-win32/glew-2.1.0/include
)


# Link dirs
target_link_directories(ProjectExternalModuleConfig
	PRIVATE glfw/src
	PRIVATE OpenGL::GL
	PRIVATE glew-2.1.0-win32/glew-2.1.0/lib/Release/x64
)


# Link libs
target_link_libraries(ProjectExternalModuleConfig 
	glfw
	OpenGL::GL
	glew32
)