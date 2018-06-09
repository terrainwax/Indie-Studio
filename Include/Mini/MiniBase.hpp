/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <irrKlang.h>
#include <irrlicht.h>
#include <Keycodes.h>
#include <IEventReceiver.h>
#pragma GCC diagnostic warning "-Wunused-parameter"

#include <stdexcept>
#include <ctime>
#include <string>
#include <map>
#include <stack>
#include <iostream>
#include <vector>

#include "Clock.hpp"

#define MENU_PATH "Assets/Menus/"
#define MUSIC_PATH "Assets/Music/"

#define OK MENU_PATH "OK.jpg"
#define KO MENU_PATH "KO.jpg"

// musics
#define MENU_MUSIC MUSIC_PATH "Menu.ogg"
#define GAME_MUSIC MUSIC_PATH "Game.ogg"

// Sounds
#define OPENING MUSIC_PATH "Opening.ogg"
#define NOCK MUSIC_PATH "Nock.ogg"
#define ON MUSIC_PATH "On.ogg"
#define OFF MUSIC_PATH "Off.ogg"
#define TOGGLE_PLAYER MUSIC_PATH "TogglePlayer.ogg"
#define TRANSITION MUSIC_PATH "Transition.ogg"
#define KONAMI_ACTIVATED MUSIC_PATH "KonamiActivated.ogg"

#define PLAYER_NUMBER 4
