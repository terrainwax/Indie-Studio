cmake_minimum_required(VERSION 3.9)
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

IF (UNIX)
    FIND_LIBRARY(XCURSOR_LIBRARY Xcursor)
    FIND_LIBRARY(XXF86VM_LIBRARY Xxf86vm)
    FIND_LIBRARY(XEXT_LIBRARY Xext)
    FIND_LIBRARY(X11_LIBRARY X11)
ENDIF (UNIX)

SET(OSX_LIBRARIES ${XCURSOR_LIBRARY} ${XXF86VM_LIBRARY} ${XEXT_LIBRARY} ${X11_LIBRARY})

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
        Src/Map.cpp
        Src/Main.cpp
        Src/Clock.cpp
        Src/Player.cpp
        Src/Obj/Cube.cpp
        Src/Obj/Sphere.cpp
        Src/ActionManager.cpp
        Src/GraphicManager.cpp)
TARGET_LINK_LIBRARIES(IrrlichtCMake ${IRRLICHT_LIBRARY}
        ${OPENGL_LIBRARIES} ${OSX_LIBRARIES})
