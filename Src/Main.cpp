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

int main(int argc, char **argv)
{
	irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640,480), 32, false, false, false);
	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager *sceneManager = device->getSceneManager();

	irr::video::ITexture *image = driver->getTexture("Assets/Textures/Bomberman.png");    // chargement de l'image
	driver->makeColorKeyTexture (image, irr::core::position2d<irr::s32> (0,0)); // transparence pour le fond

	irr::video::SColor blanc;                                          // creation variable couleur blanche
	blanc.set(255,255,255,255);

	while(device->run ())                                              // la boucle de rendu
	{
	driver->beginScene(true, true,
		irr::video::SColor (0,120,120,120));
	driver->draw2DImage(image,                                     // dessin de la salle
		irr::core::position2d<irr::s32> (20,20),
		irr::core::rect<irr::s32> (0,0,342,224),
		0, blanc, true);
	driver->draw2DImage (image,                                    // dessin du premier truc rouge
		irr::core::position2d<irr::s32> (140,140),
		irr::core::rect<irr::s32> (349,15,385,78),
		0, blanc, true);
	driver->draw2DImage (image,                                    // dessin du deuxième truc rouge
		irr::core::position2d<irr::s32> (150,20),
		irr::core::rect<irr::s32> (387,15,423,78),
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
