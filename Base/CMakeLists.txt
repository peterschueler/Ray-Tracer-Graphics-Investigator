CMAKE_MINIMUM_REQUIRED(VERSION 3.4)

IF (NOT_CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
ENDIF()

PROJECT(RAYTRACER)

SET(dot_VERSION_MAJOR 0)
SET(dot_VERSION_MINOR 1)

CONFIGURE_FILE(
	"${PROJECT_SOURCE_DIR}/Utilities/Config.h.in"
	"${PROJECT_SOURCE_DIR}/Utilities/Config.h"
)
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

SET(EXECUTABLE_NAME "RayTracer")
ADD_EXECUTABLE(${EXECUTABLE_NAME} Interface/main.cpp Interface/Application.cpp Utilities/ShadeRec.cpp Utilities/Ray.cpp GeometricObjects/GeometricObject.cpp GeometricObjects/Sphere.cpp Tracers/Tracer.cpp Tracers/SingleSphere.cpp World/ViewPlane.cpp World/World.cpp)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake_Modules" ${CMAKE_MODULE_PATH})

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++14 -Wall")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++14 -Wall -Werror")

FIND_PACKAGE(SFML 2 REQUIRED system window graphics network audio)
IF (SFML_FOUND)
	INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
	TARGET_LINK_LIBRARIES(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
ENDIF()