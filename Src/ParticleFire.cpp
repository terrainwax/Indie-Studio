/*
** EPITECH PROJECT, 2021
** cpp_indie_studio
** File description:
** Created by terrainwax,
*/
#include <IParticleEmitter.h>
#include <GraphicManager.hpp>
#include "ParticleFire.hpp"

ParticleFire::ParticleFire(irr::scene::ISceneManager *smgr,
	irr::core::vector3df pos, GraphicManager graph, long dura
) :
_smgr(smgr),_pos(pos), _graph(graph), _duration(dura)
{
	_ps = smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter* em = _ps->createBoxEmitter(
		irr::core::aabbox3d<irr::f32>(-1,0,-1,1,1,1),
		irr::core::vector3df(0.0f,0.06f,0.0f),
		80,100,
		irr::video::SColor(0,255,255,255),
		irr::video::SColor(0,255,255,255),
		200,300,0,
		irr::core::dimension2df(10.f,10.f),
		irr::core::dimension2df(20.f,20.f));

	_ps->setEmitter(em);
	em->drop();

	irr::scene::IParticleAffector* paf = _ps->createFadeOutParticleAffector();

	_ps->addAffector(paf);
	paf->drop();

	_ps->setPosition(pos);
	_ps->setScale(irr::core::vector3df(0.1,0.1,0.1));
	_ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	_ps->setMaterialTexture(0, _graph.getVideoDriver()->getTexture("Assets/Textures/fire.bmp"));
	_ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

}

ParticleFire::~ParticleFire()
{

}

irr::scene::IParticleSystemSceneNode *ParticleFire::getParticle()
{
	return _ps;
}

int ParticleFire::update()
{
	_duration--;
	if (_duration == 0) {
		_ps->setEmitter(0);
		return 1;
	}
	return 0;
}
