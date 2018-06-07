/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include "Menu.hpp"

#include <iostream>

Menu::Menu(irr::IrrlichtDevice *device, ActionManager *actions, SoundManager *sounds)
	: _device(device), _actions(actions), _sounds(sounds)
{
}

Menu::~Menu()
{

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
				launchGame();
			if (choice == 1)
				launchOptions();
			if (choice == 2)
				break;
			// else
				// break;
		}

		if (_actions->isKeyPressed(irr::KEY_ESCAPE))
			break;

		_actions->flush();
	}

	_actions->flush();
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
			// else
				// break;
		}

		if (_actions->isKeyPressed(irr::KEY_ESCAPE))
			break;

		_actions->flush();
	}

	_actions->flush();
}

void Menu::launchGame()
{
	_actions->flush();

	GraphicManager graphics(_device);

	graphics.createSkybox("Assets/Textures/skyfield.jpg");

	Game game;
	game.addPlayer(new Player(1, 1, "test", graphics.getSceneManager(), KeySetUtils::dflKeySet1));
	game.addPlayer(new Player(1, 1, "test", graphics.getSceneManager(), KeySetUtils::dflKeySet2));
	game.addPlayer(new Player(1, 2, "test", graphics.getSceneManager(), KeySetUtils::dflKeySet2));

	_sounds->playBgm(SOUND("GroSonSaRace.ogg"));
	while (graphics.isActive() && game.isOnGoing() && !_actions->isKeyPressed(irr::KEY_ESCAPE)) {
		game.display(graphics);
		game.update(*_actions, graphics, *_sounds);
		graphics.render();
	}

	_actions->flush();
}
