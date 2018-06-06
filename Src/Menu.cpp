#include "Menu.hpp"

Menu::Menu(irr::IrrlichtDevice *device, ActionManager *actions, SoundManager *sounds)
	: _device(device), _actions(actions), _sounds(sounds)
{

}

Menu::~Menu()
{

}

void Menu::run()
{
	irr::video::IVideoDriver* driver = _device->getVideoDriver();

	irr::video::ITexture *imageBlue = driver->getTexture("Assets/Menus/StartGameBlue.jpg");
	irr::video::ITexture *imageRed = driver->getTexture("Assets/Menus/StartGameRed.jpg");

	irr::video::SColor blanc[4];
	blanc[0].set(255,255,255,255);
	blanc[1].set(255,255,255,255);
	blanc[2].set(255,255,255,255);
	blanc[3].set(255,255,255,255);

	Clock clock;

	while(_device->run() && !_actions->isKeyPressed(irr::KEY_RETURN))
	{
		clock.tick();

		irr::video::ITexture *image = (clock.elapsedMilliseconds() % 1000 > 500) ? imageBlue : imageRed;
		driver->beginScene(true, true, irr::video::SColor (0,120,120,120));
		driver->draw2DImage(image,
			irr::core::rect<irr::s32> (0, 0, WINDOW_WIDTH, WINDOW_HEIGHT),
			irr::core::rect<irr::s32> (0,0, image->getOriginalSize().Width, image->getOriginalSize().Height), 0, blanc, true);
		driver->endScene();
	}

	GraphicManager graphics(_device);

	graphics.createSkybox("Assets/Textures/skyfield.jpg");
	Game game;
	game.addPlayer(new Player(1, 1, "test", graphics.getSceneManager(), KeySetUtils::dflKeySet1));
	game.addPlayer(new Player(1, 1, "test", graphics.getSceneManager(), KeySetUtils::dflKeySet2));
	game.addPlayer(new Player(1, 2, "test", graphics.getSceneManager(), KeySetUtils::dflKeySet2));

	_sounds->playBgm(SOUND("GroSonSaRace.ogg"));
	while (graphics.isActive() && game.isOnGoing()) {
		game.display(graphics);
		game.update(*_actions, graphics, *_sounds);
		graphics.render();
	}
}