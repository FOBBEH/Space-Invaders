#include <iostream>
#include <cstdlib>

#include "SpriteManager.h"

SpriteManager *SpriteManager::m_theInstance = NULL;

SpriteManager &SpriteManager::Get()
{
	if (m_theInstance == NULL)
	{
		m_theInstance = new SpriteManager;
	}

	return *m_theInstance;
}

void SpriteManager::Destroy()
{
	delete m_theInstance;
	m_theInstance = NULL;
}

int SpriteManager::LoadSprites()
{
	// Prepare our images:
	if (!spaceInvaders.LoadFromFile	("data/spaceinvaders.png")) 
		cout << "SPACE INVADERS SPRITES DID NOT LOAD OMG!" << endl;
	if (!screens.LoadFromFile ("data/screens.png"))
		cout << "SCREENS DID NOT LOAD OMGGGGGGG!" << endl;

	// Set the sprites to the images:
	player			= spaceInvaders;
	playerBullet	= spaceInvaders;
	enemyA			= spaceInvaders;
	enemyB			= spaceInvaders;
	enemyC			= spaceInvaders;
	enemyBulletA	= spaceInvaders;
	enemyBulletB	= spaceInvaders;
	UFO				= spaceInvaders;
	shieldA			= spaceInvaders;
	shieldB			= spaceInvaders;
	shieldC			= spaceInvaders;
	shieldD			= spaceInvaders;
	shieldE			= spaceInvaders;
	titleScreen		= screens;
	pauseScreen		= screens;
	highScoreScreen = screens;

	player.SetSubRect(IntRect(134,20,185,51));			// Co-ordinates to select sprite TOP LEFT, BOTTOM RIGHT
	player.SetCenter(26,16);							// Co-ordinates to set the center of the sprite

	playerBullet.SetSubRect(IntRect(154,85,165,108)); 
	playerBullet.SetCenter(6, 12); 

	enemyA.SetSubRect(IntRect(0,0,64,64));
	enemyA.SetCenter(32,32);

	enemyB.SetSubRect(IntRect(0,64,64,128));
	enemyB.SetCenter(32,32);

	enemyC.SetSubRect(IntRect(0,128,64,192));
	enemyC.SetCenter(32,32);

	enemyBulletA.SetSubRect(IntRect(192,64,256,128));
	enemyBulletA.SetCenter(32,32);

	enemyBulletB.SetSubRect(IntRect(256,64,320,128));
	enemyBulletB.SetCenter(32,32);

	UFO.SetSubRect(IntRect(192,128,320,192));
	UFO.SetCenter(64,32);

	shieldA.SetSubRect(IntRect(0,192,64,256));
	shieldA.SetCenter(32,32);

	shieldB.SetSubRect(IntRect(64,192,128,256));
	shieldB.SetCenter(32,32);

	shieldC.SetSubRect(IntRect(128,192,192,256));
	shieldC.SetCenter(32,32);

	shieldD.SetSubRect(IntRect(192,192,256,256));
	shieldD.SetCenter(32,32);

	shieldE.SetSubRect(IntRect(256,192,320,256));
	shieldE.SetCenter(32,32);

	titleScreen.SetSubRect(IntRect(0,0,1280,720));
	titleScreen.SetCenter(0,0);

	pauseScreen.SetSubRect(IntRect(0,720,1280,1440));
	pauseScreen.SetCenter(0,0);

	highScoreScreen.SetSubRect(IntRect(0,1440, 1280, 2160));
	highScoreScreen.SetCenter(0,0);

	return EXIT_SUCCESS;
}