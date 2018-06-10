/*
** EPITECH PROJECT, 2021
** cpp_indie_studio
** File description:
** Created by terrainwax,
*/
#ifndef CPP_INDIE_STUDIO_PARTICLEFIRE_HPP
# define CPP_INDIE_STUDIO_PARTICLEFIRE_HPP

#include <vector3d.h>
#include <ISceneManager.h>
#include "GraphicManager.hpp"

class ParticleFire
{
	public:
		ParticleFire(irr::scene::ISceneManager *_smgr, irr::core::vector3df pos, GraphicManager	graph, long dura);
		~ParticleFire();
		irr::scene::IParticleSystemSceneNode* getParticle();
		int update();
	private:
		irr::scene::ISceneManager *_smgr;
		irr::core::vector3df	_pos;
		irr::scene::IParticleSystemSceneNode* _ps;
		GraphicManager	_graph;
		long _duration;
};

#endif //CPP_INDIE_STUDIO_PARTICLEFIRE_HPP
