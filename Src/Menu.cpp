/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include <iostream>

#include "Menu.hpp"


Menu::Menu(irr::IrrlichtDevice *device, ActionManager *actions, SoundManager *sounds)
: _device(device), _actions(actions), _sounds(sounds)
{
	for (int i = 0; i < PLAYER_NUMBER; i++) {
		_com[i] = false;
	}
}

Menu::~Menu()
{
}

void Menu::togglePlayer(char player)
{
	_com[player] = !_com[player];
}

void Menu::run()
{
	_actions->flush();

	irr::video::IVideoDriver* driver = _device->getVideoDriver();

	irr::video::ITexture *imageBlue = driver->getTexture("Assets/Menus/StartGameBlue.jpg");
	irr::video::ITexture *imageRed = driver->getTexture("Assets/Menus/StartGameRed.jpg");

	irr::video::SColor blanc[4];
	blanc[0].set(255,255,255,255);
	blanc[1].set(255,255,255,255);
	blanc[2].set(255,255,255,255);
	blanc[3].set(255,255,255,255);

	Clock clock;

	while(_device->run())
	{
		clock.tick();

		irr::video::ITexture *image = (clock.elapsedMilliseconds() % 1000 > 500) ? imageBlue : imageRed;
		driver->beginScene(true, true, irr::video::SColor (0,120,120,120));
		driver->draw2DImage(image,
			irr::core::rect<irr::s32> (0, 0, driver->getScreenSize().Width, driver->getScreenSize().Height),
			irr::core::rect<irr::s32> (0,0, image->getOriginalSize().Width, image->getOriginalSize().Height), 0, blanc, true);
		driver->endScene();

		if (_actions->isKeyPressed(irr::KEY_RETURN))
			chooseScreen();

		if (_actions->isKeyPressed(irr::KEY_ESCAPE))
			break;
	}

	_actions->flush();
}

void Menu::chooseScreen()
{
	_actions->flush();

	irr::video::IVideoDriver* driver = _device->getVideoDriver();

	irr::video::ITexture *imageStart = driver->getTexture("Assets/Menus/GameMenuStart.jpg");
	irr::video::ITexture *imageOptions = driver->getTexture("Assets/Menus/GameMenuOptions.jpg");
	irr::video::ITexture *imageExit = driver->getTexture("Assets/Menus/GameMenuExit.jpg");

	irr::video::SColor blanc[4];
	blanc[0].set(255,255,255,255);
	blanc[1].set(255,255,255,255);
	blanc[2].set(255,255,255,255);
	blanc[3].set(255,255,255,255);

	Clock clock;

	char choice = 0;

	while(_device->run())
	{
		clock.tick();

		irr::video::ITexture *image = (choice == 0) ? imageStart : ((choice == 1) ? imageOptions : imageExit);

		driver->beginScene(true, true, irr::video::SColor (0,120,120,120));
		driver->draw2DImage(image,
			irr::core::rect<irr::s32> (0, 0, driver->getScreenSize().Width, driver->getScreenSize().Height),
			irr::core::rect<irr::s32> (0,0, image->getOriginalSize().Width, image->getOriginalSize().Height), 0, blanc, true);
		driver->endScene();

		if (_actions->isKeyPressed(irr::KEY_UP))
			choice = (3 + (choice - 1)) % 3;

		if (_actions->isKeyPressed(irr::KEY_DOWN))
			choice = (3 + (choice + 1)) % 3;

		if (_actions->isKeyPressed(irr::KEY_RETURN))
		{
			if (choice == 0)
				launchPlayerChoice();
			if (choice == 1)
				launchOptions();
			if (choice == 2)
				break;
		}

		if (_actions->isKeyPressed(irr::KEY_ESCAPE))
			break;

		_actions->flush();
	}

	_actions->flush();
}

void Menu::launchPlayerChoice()
{
	_actions->flush();

	for (int i = 0; i < PLAYER_NUMBER; i++) {
		_com[i] = false;
	}

	irr::video::IVideoDriver* driver = _device->getVideoDriver();

	irr::video::ITexture *imagePlayer1 = driver->getTexture("Assets/Menus/StartMenuPlayer1.jpg");
	irr::video::ITexture *imagePlayer2 = driver->getTexture("Assets/Menus/StartMenuPlayer2.jpg");
	irr::video::ITexture *imagePlayer3 = driver->getTexture("Assets/Menus/StartMenuPlayer3.jpg");
	irr::video::ITexture *imagePlayer4 = driver->getTexture("Assets/Menus/StartMenuPlayer4.jpg");
	irr::video::ITexture *imageStart = driver->getTexture("Assets/Menus/StartMenuStart.jpg");

	irr::video::ITexture *comOn = driver->getTexture("Assets/Menus/OK.jpg");
	irr::video::ITexture *comOff = driver->getTexture("Assets/Menus/KO.jpg");

	irr::video::SColor blanc[4];
	blanc[0].set(255,255,255,255);
	blanc[1].set(255,255,255,255);
	blanc[2].set(255,255,255,255);
	blanc[3].set(255,255,255,255);

	Clock clock;

	char choice = 0;

	while(_device->run())
	{
		clock.tick();

		irr::video::ITexture *com1 = (_com[0]) ? comOn : comOff;
		irr::video::ITexture *com2 = (_com[1]) ? comOn : comOff;
		irr::video::ITexture *com3 = (_com[2]) ? comOn : comOff;
		irr::video::ITexture *com4 = (_com[3]) ? comOn : comOff;

		irr::video::ITexture *image = (choice == 0) ? imagePlayer1 : ((choice == 1) ? imagePlayer2 : ((choice == 2) ? imagePlayer3 : ((choice == 3) ? imagePlayer4 : imageStart)));

		driver->beginScene(true, true, irr::video::SColor (0,120,120,120));
		driver->draw2DImage(image,
			irr::core::rect<irr::s32> (0, 0, driver->getScreenSize().Width, driver->getScreenSize().Height),
			irr::core::rect<irr::s32> (0,0, image->getOriginalSize().Width, image->getOriginalSize().Height), 0, blanc, true);
		displayChecks(driver, com1, com2, com3, com4, blanc);
		driver->endScene();

		if (_actions->isKeyPressed(irr::KEY_UP))
			choice = (5 + (choice - 1)) % 5;

		if (_actions->isKeyPressed(irr::KEY_DOWN))
			choice = (5 + (choice + 1)) % 5;

		if (_actions->isKeyPressed(irr::KEY_RETURN))
		{
			if (choice >= 0 && choice <= 3)
				togglePlayer(choice);
			if (choice == 4)
				launchGame();
		}

		if (_actions->isKeyPressed(irr::KEY_ESCAPE))
			break;

		_actions->flush();
	}

	_actions->flush();
}

void displayChecks(irr::video::IVideoDriver *driver, irr::video::ITexture *com1, irr::video::ITexture *com2, irr::video::ITexture *com3, irr::video::ITexture *com4, irr::video::SColor *blanc)
{
	driver->draw2DImage(com1,
		irr::core::rect<irr::s32> ((int)((float)driver->getScreenSize().Width * 0.855f), (int)((float)driver->getScreenSize().Height * 0.082f), (int)((float)driver->getScreenSize().Width * 0.884f), (int)((float)driver->getScreenSize().Height * 0.122f)),
		irr::core::rect<irr::s32> (0,0, com1->getOriginalSize().Width, com1->getOriginalSize().Height), 0, blanc, true);
	driver->draw2DImage(com2,
		irr::core::rect<irr::s32> ((int)((float)driver->getScreenSize().Width * 0.855f), (int)((float)driver->getScreenSize().Height * 0.285f), (int)((float)driver->getScreenSize().Width * 0.884f), (int)((float)driver->getScreenSize().Height * 0.325f)),
		irr::core::rect<irr::s32> (0,0, com2->getOriginalSize().Width, com2->getOriginalSize().Height), 0, blanc, true);
	driver->draw2DImage(com3,
		irr::core::rect<irr::s32> ((int)((float)driver->getScreenSize().Width * 0.855f), (int)((float)driver->getScreenSize().Height * 0.480f), (int)((float)driver->getScreenSize().Width * 0.884f), (int)((float)driver->getScreenSize().Height * 0.520f)),
		irr::core::rect<irr::s32> (0,0, com3->getOriginalSize().Width, com3->getOriginalSize().Height), 0, blanc, true);
	driver->draw2DImage(com4,
		irr::core::rect<irr::s32> ((int)((float)driver->getScreenSize().Width * 0.855f), (int)((float)driver->getScreenSize().Height * 0.683f), (int)((float)driver->getScreenSize().Width * 0.884f), (int)((float)driver->getScreenSize().Height * 0.723f)),
		irr::core::rect<irr::s32> (0,0, com4->getOriginalSize().Width, com4->getOriginalSize().Height), 0, blanc, true);
}

void Menu::launchOptions()
{
	_actions->flush();

	irr::video::IVideoDriver* driver = _device->getVideoDriver();

	irr::video::ITexture *optionsAudio = driver->getTexture("Assets/Menus/OptionsMenuAudio.jpg");
	irr::video::ITexture *optionsBack = driver->getTexture("Assets/Menus/OptionsMenuBack.jpg");
	irr::video::ITexture *audioOn = driver->getTexture("Assets/Menus/OK.jpg");
	irr::video::ITexture *audioOff = driver->getTexture("Assets/Menus/KO.jpg");

	irr::video::SColor blanc[4];
	blanc[0].set(255,255,255,255);
	blanc[1].set(255,255,255,255);
	blanc[2].set(255,255,255,255);
	blanc[3].set(255,255,255,255);

	Clock clock;

	char choice = 0;

	while(_device->run())
	{
		clock.tick();

		irr::video::ITexture *image = (choice == 0) ? optionsAudio : optionsBack;
		irr::video::ITexture *audio = (_sounds->getAudioStatus()) ? audioOn : audioOff;

		driver->beginScene(true, true, irr::video::SColor (0,120,120,120));
		driver->draw2DImage(image,
			irr::core::rect<irr::s32> (0, 0, driver->getScreenSize().Width, driver->getScreenSize().Height),
			irr::core::rect<irr::s32> (0,0, image->getOriginalSize().Width, image->getOriginalSize().Height), 0, blanc, true);
		driver->draw2DImage(audio,
			irr::core::rect<irr::s32> ((int)((float)driver->getScreenSize().Width * 0.535f), (int)((float)driver->getScreenSize().Height * 0.21f), (int)((float)driver->getScreenSize().Width * 0.564f), (int)((float)driver->getScreenSize().Height * 0.25f)),
			irr::core::rect<irr::s32> (0,0, audio->getOriginalSize().Width, audio->getOriginalSize().Height), 0, blanc, true);
		driver->endScene();

		if (_actions->isKeyPressed(irr::KEY_UP))
			choice = (2 + (choice - 1)) % 2;

		if (_actions->isKeyPressed(irr::KEY_DOWN))
			choice = (2 + (choice + 1)) % 2;

		if (_actions->isKeyPressed(irr::KEY_RETURN))
		{
			if (choice == 0) {
				_sounds->toggleAudio();
			}
			if (choice == 1)
				break;
		}

		if (_actions->isKeyPressed(irr::KEY_ESCAPE))
			break;

		_actions->flush();
	}

	_actions->flush();
}

void Menu::addPlayer(Game &game, GraphicManager &graphics, int mapSize)
{
	int spawnX[PLAYER_NUMBER] = {
		1,
		1,
		mapSize - 2,
		mapSize - 2
	};
	int spawnY[PLAYER_NUMBER] = {
		1,
		mapSize - 2,
		mapSize - 2,
		1
	};
	KeySet keyMap[PLAYER_NUMBER] = {
		KeySetUtils::dflKeySet1,
		KeySetUtils::dflKeySet2,
		KeySetUtils::dflKeySet3,
		KeySetUtils::dflKeySet4
	};
	for (int i = 0; i < PLAYER_NUMBER; i++) {
		if (_com[i] == false)
			game.addPlayer(new Player(spawnX[i], spawnY[i], "Player", graphics.getSceneManager(), keyMap[i]));
	}
	for (int i = 0; i < PLAYER_NUMBER; i++) {
		if (_com[i] == true)
			game.addPlayer(new AI(spawnX[i], spawnY[i], "AI", graphics.getSceneManager()));
	}
}

void Menu::launchGame()
{
	_actions->flush();

	GraphicManager graphics(_device);

	graphics.createSkybox("Assets/Textures/skyfield.jpg");
	int mapSize = 15;
	int playerNb = 0; 

	Game game(mapSize);
	
	this->addPlayer(game, graphics, mapSize);
	for (int i = 0; i < PLAYER_NUMBER; i++)
		playerNb = _com[i] ? playerNb : playerNb + 1;
	if (playerNb <= 1)
		game.setSkyView(false);
	_sounds->playBgm(SOUND("GroSonSaRace.ogg"));
	while (graphics.isActive() && game.isOnGoing() && !_actions->isKeyPressed(irr::KEY_ESCAPE)) {
		game.display(graphics);
		game.update(*_actions, graphics, *_sounds);
		graphics.render();
	}
	_sounds->playBgm(SOUND("Menu.ogg"));
	_actions->flush();
}
