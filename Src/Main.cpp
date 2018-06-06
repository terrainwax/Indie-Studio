/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include <ctime>
#include "Game.hpp"
#include "Map.hpp"
#include "BombUp.hpp"
#include "SoundManager.hpp"
#include "GraphicManager.hpp"
#include "PowerUpFactory.hpp"
#include "Clock.hpp"

int main(int argc, char **argv)
{
	irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(WINDOW_WIDTH,WINDOW_HEIGHT), WINDOW_BITS, false, false, false);
	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager *sceneManager = device->getSceneManager();

	irr::video::ITexture *imageBlue = driver->getTexture("Assets/Menus/StartGameBlue.jpg");    // chargement de l'image
	irr::video::ITexture *imageRed = driver->getTexture("Assets/Menus/StartGameRed.jpg");
	//driver->makeColorKeyTexture (image, irr::core::position2d<irr::s32> (0,0)); // transparence pour le fond

	irr::video::SColor blanc[4];                                          // creation variable couleur blanche
	blanc[0].set(255,255,255,255);
	blanc[1].set(255,255,255,255);
	blanc[2].set(255,255,255,255);
	blanc[3].set(255,255,255,255);

	Clock clock;

	while(device->run ())                                              // la boucle de rendu
	{
		clock.tick();

		irr::video::ITexture *image = (clock.elapsedMilliseconds() % 1000 > 500) ? imageBlue : imageRed;
	driver->beginScene(true, true,
		irr::video::SColor (0,120,120,120));
	driver->draw2DImage(image,                                     // dessin de la salle
		irr::core::rect<irr::s32> (0, 0, WINDOW_WIDTH, WINDOW_HEIGHT),
		irr::core::rect<irr::s32> (0,0, image->getOriginalSize().Width, image->getOriginalSize().Height),
		0, blanc, true);
		driver->endScene ();
	}

	device->drop ();
	/*
	(void)argc;
	(void)argv;
	srand(time(NULL));
	SoundManager sound;
	ActionManager action;
	GraphicManager graphic(action);
	graphic.createSkybox("Assets/Textures/skyfield.jpg");
	Game game;
	game.addPlayer(new Player(1, 1, "test", graphic.getSceneManager(), KeySetUtils::dflKeySet1));
	game.addPlayer(new Player(1, 1, "test", graphic.getSceneManager(), KeySetUtils::dflKeySet2));
	game.addPlayer(new Player(1, 2, "test", graphic.getSceneManager(), KeySetUtils::dflKeySet2));

	sound.playBgm(SOUND("GroSonSaRace.ogg"));
	while (graphic.isActive() && game.isOnGoing()) {
		game.display(graphic);
		game.update(action, graphic, sound);
		graphic.render();
	}*/
	return 0;
}
