cmake_minimum_required(VERSION 3.10)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

FIND_PACKAGE(OpenGL)
FIND_PACKAGE(Irrlicht)

IF (APPLE)
    FIND_LIBRARY(CARBON_LIBRARY Carbon)
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(IOKIT_LIBRARY IOKit)
    SET(OSX_LIBRARIES ${CARBON_LIBRARY} ${COCOA_LIBRARY} ${IOKIT_LIBRARY})
ENDIF (APPLE)

INCLUDE_DIRECTORIES(${IRRLICHT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
include_directories(Include)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

ADD_EXECUTABLE(IrrlichtCMake WIN32 MACOSX_BUNDLE
        Include/ActionManager.hpp
        Include/Clock.hpp
        Include/Cube.hpp
        Include/GraphicManager.hpp
        Include/Map.hpp
        Include/Sphere.hpp
        Src/ActionManager.cpp
        Src/Clock.cpp
        Src/Cube.cpp
        Src/GraphicManager.cpp
        Src/Main.cpp
        Src/Map.cpp
        Src/Sphere.cpp)
TARGET_LINK_LIBRARIES(IrrlichtCMake ${IRRLICHT_LIBRARY}
        ${OPENGL_LIBRARIES} ${OSX_LIBRARIES})
