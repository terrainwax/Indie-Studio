cmake_minimum_required(VERSION 3.5)
project(cpp_indie_studio)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

FIND_PACKAGE(OpenGL)
FIND_PACKAGE(Irrlicht)

IF (APPLE)
    FIND_LIBRARY(CARBON_LIBRARY Carbon)
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(IOKIT_LIBRARY IOKit)
    SET(OSX_LIBRARIES ${CARBON_LIBRARY} ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${XCURSOR_LIBRARY} ${XXF86VM_LIBRARY} ${XEXT_LIBRARY} ${X11_LIBRARY})
ENDIF (APPLE)

IF (UNIX)
    FIND_LIBRARY(XCURSOR_LIBRARY Xcursor)
    FIND_LIBRARY(XXF86VM_LIBRARY Xxf86vm)
    FIND_LIBRARY(XEXT_LIBRARY Xext)
    FIND_LIBRARY(X11_LIBRARY X11)
    FIND_LIBRARY(IRRKLANG IrrKlang)
    SET(OSX_LIBRARIES ${XCURSOR_LIBRARY} ${IRRKLANG} ${XXF86VM_LIBRARY} ${XEXT_LIBRARY} ${X11_LIBRARY})
ENDIF (UNIX)

INCLUDE_DIRECTORIES(${IRRLICHT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})

INCLUDE_DIRECTORIES(Include)
INCLUDE_DIRECTORIES(Include/Mini)
INCLUDE_DIRECTORIES(Include/PowerUp)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/Binaries)

ADD_EXECUTABLE(indie WIN32 MACOSX_BUNDLE ${SOURCE}
        Src/Clock.cpp
        Src/Mini/MiniMain.cpp
        Src/Mini/MiniCore.cpp
        Src/Mini/MiniRectangle.cpp
        Src/Mini/MiniSprite.cpp
        Src/Mini/MiniAudioMgr.cpp
        Src/Mini/MiniVideoMgr.cpp
        Src/Mini/MiniScene.cpp
        Src/Mini/MiniSceneIntro.cpp
        Src/Mini/MiniSceneMenu.cpp
        Src/Mini/MiniSceneOptions.cpp
        Src/Mini/MiniScenePlayers.cpp
        Src/Mini/MiniSceneBomber.cpp
        Src/Mini/MiniSceneVictory.cpp
        Src/Mini/MiniSceneKonami.cpp
        Src/ActionManager.cpp
        Src/AI.cpp
        Src/Map.cpp
        Src/Bomb.cpp
        Src/Clock.cpp
        Src/KeySet.cpp
        Src/Player.cpp
        Src/Game.cpp
        Src/APlayer.cpp
        Src/Obj/Cube.cpp
        Src/Obj/Sphere.cpp
        Src/SoundManager.cpp
        Src/PowerUp/BombUp.cpp
        Src/PowerUp/FireUp.cpp
        Src/GraphicManager.cpp
        Src/PowerUp/LifeUp.cpp
        Src/PowerUp/SpeedUp.cpp
        Src/PowerUp/APowerUp.cpp
        Src/PowerUp/FullFire.cpp
        Src/PowerUp/PierceUp.cpp
        Src/PowerUp/WallPass.cpp
        Src/PowerUp/PowerUpFactory.cpp
        Src/ParticleFire.cpp
        Include/ParticleFire.hpp)
TARGET_LINK_LIBRARIES(indie ${IRRLICHT_LIBRARY}
        ${OPENGL_LIBRARIES} ${OSX_LIBRARIES})

install(TARGETS indie DESTINATION bin)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Binaries)

