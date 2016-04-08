// SpriteManager.h

#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class SpriteManager
{
public:
	static SpriteManager &	Get();
	static void				Destroy();

	int						LoadSprites();

	Sprite &				GetPlayer()				{ return player; }
	Sprite &				GetPlayerBullet()		{ return playerBullet; }
	Sprite &				GetEnemyA()				{ return enemyA; }
	Sprite &				GetEnemyB()				{ return enemyB; }
	Sprite &				GetEnemyC()				{ return enemyC; }
	Sprite &				GetEnemyBulletA()		{ return enemyBulletA; }
	Sprite &				GetEnemyBulletB()		{ return enemyBulletB; }
	Sprite &				GetUFO()				{ return UFO; }
	Sprite &				GetShieldA()			{ return shieldA; }
	Sprite &				GetShieldB()			{ return shieldB; }
	Sprite &				GetShieldC()			{ return shieldC; }
	Sprite &				GetShieldD()			{ return shieldD; }
	Sprite &				GetShieldE()			{ return shieldE; }
	Sprite &				GetTitleScreen()		{ return titleScreen; }
	Sprite &				GetPauseScreen()		{ return pauseScreen; }
	Sprite &				GetHighScoreScreen()	{ return highScoreScreen; }

private:
	static SpriteManager *	m_theInstance;

	SpriteManager() {}
	~SpriteManager() {}

	Image					spaceInvaders;
	Image					screens;

	Sprite					player;
	Sprite					playerBullet;
	Sprite					enemyA;
	Sprite					enemyB;
	Sprite					enemyC;
	Sprite					enemyBulletA;
	Sprite					enemyBulletB;
	Sprite					UFO;
	Sprite					shieldA;
	Sprite					shieldB;
	Sprite					shieldC;
	Sprite					shieldD;
	Sprite					shieldE;
	Sprite					titleScreen;
	Sprite					pauseScreen;
	Sprite					highScoreScreen;
};

#endif // SPRITEMANAGER_H