#include <time.h>

#include "Enemy.h"
#include "Bullet.h"

EnemyList EnemyListA;
EnemyList EnemyListB;
EnemyList EnemyListC;
EnemyList EnemyListD;
EnemyList EnemyListE;
EnemyList UFOList;

bool canShoot = true;

bool enemyMoveRight = true;
bool UFOCanSpawn = true;

int EnemyBulletTimer = 100;

int UFOPosition = 1280;
int gameLevel = 1;
int enemySpeed = 20;
int edgeCounter = 0;
int whichEnemyIsAlive = 0;

void CreateEnemies(int gameLevel)
{
	for (int i = 0; i < 11; ++i)		// 11 enemies
	{
		// Set spawning positions:
		Enemy enemyA;					// Top row
		enemyA.x = 100 + (i * 60);
		enemyA.y = 100 + ((gameLevel-1) * 25);
		enemyA.isDead = false;
		enemyA.points = 300;
		EnemyListA.push_back( enemyA );

		Enemy enemyB;
		enemyB.x = 100 + (i * 60);
		enemyB.y = 150 + ((gameLevel-1) * 25);
		enemyB.isDead = false;
		enemyB.points = 200;
		EnemyListB.push_back( enemyB );

		Enemy enemyC;
		enemyC.x = 100 + (i * 60);
		enemyC.y = 200 + ((gameLevel-1) * 25);
		enemyC.isDead = false;
		enemyC.points = 200;
		EnemyListC.push_back( enemyC );

		Enemy enemyD;
		enemyD.x = 100 + (i * 60);
		enemyD.y = 250 + ((gameLevel-1) * 25);
		enemyD.isDead = false;
		enemyD.points = 100;
		EnemyListD.push_back( enemyD );

		Enemy enemyE;					// Bottom row
		enemyE.x = 100 + (i * 60);
		enemyE.y = 300 + ((gameLevel-1) * 25);
		enemyE.isDead = false;
		enemyE.points = 100;
		EnemyListE.push_back( enemyE );
	}
}

void UpdateEnemies(float deltaT)
{
	// Enemies move left and right
	whichEnemyIsAlive = EnemyCheckColumn(EnemyListA, EnemyListB, EnemyListC, EnemyListD, EnemyListE, enemyMoveRight);

	if (enemyMoveRight)
	{
		for (int i = 0; i < EnemyListA.size(); ++i)
		{
			EnemyListA[i].x += enemySpeed * deltaT;
		}
		for (int i = 0; i < EnemyListB.size(); ++i)
		{
			EnemyListB[i].x += enemySpeed * deltaT;
		}
		for (int i = 0; i < EnemyListC.size(); ++i)
		{
			EnemyListC[i].x += enemySpeed * deltaT;
		}
		for (int i = 0; i < EnemyListD.size(); ++i)
		{
			EnemyListD[i].x += enemySpeed * deltaT;
		}
		for (int i = 0; i < EnemyListE.size(); ++i)
		{
			EnemyListE[i].x += enemySpeed * deltaT;
		}
	}
	
	if (EnemyListA[whichEnemyIsAlive].x > 1120 && enemyMoveRight)
	{
		enemyMoveRight = false;
		EnemyMoveDown();
		++edgeCounter;
	}
	
	if (!enemyMoveRight)
	{
		for (int i = 0; i < EnemyListA.size(); ++i)
		{
			EnemyListA[i].x -= enemySpeed * deltaT;
		}
		for (int i = 0; i < EnemyListB.size(); ++i)
		{
			EnemyListB[i].x -= enemySpeed * deltaT;
		}
		for (int i = 0; i < EnemyListC.size(); ++i)
		{
			EnemyListC[i].x -= enemySpeed * deltaT;
		}
		for (int i = 0; i < EnemyListD.size(); ++i)
		{
			EnemyListD[i].x -= enemySpeed * deltaT;
		}
		for (int i = 0; i < EnemyListE.size(); ++i)
		{
			EnemyListE[i].x -= enemySpeed * deltaT;
		}
	}
	
	if (EnemyListA[whichEnemyIsAlive].x < 160 && !enemyMoveRight)
	{
		enemyMoveRight = true;
		EnemyMoveDown();
		++edgeCounter;
	}
	
	for (int i = 0; i < UFOList.size(); ++i)
	{
		UFOList[i].x -= 250 * deltaT;
	}

	// Speed modifier for lengthier levels:
	if ( (edgeCounter % 2 == 0) && (edgeCounter != 0) )
	{
		enemySpeed += 20;
		edgeCounter = 0;
	}
}

void RenderEnemies(RenderWindow &window)
{
	for (int i = 0; i < EnemyListA.size(); ++i)
	{
		// Draw if enemy is alive:
		if (!EnemyListA[i].isDead)
		{
			SpriteManager::Get().GetEnemyA().SetPosition( EnemyListA[i].x, EnemyListA[i].y );
			window.Draw( SpriteManager::Get().GetEnemyA() );
		}
	}
	for (int i = 0; i < EnemyListB.size(); ++i)
	{
		if (!EnemyListB[i].isDead)
		{
			SpriteManager::Get().GetEnemyB().SetPosition( EnemyListB[i].x, EnemyListB[i].y );
			window.Draw( SpriteManager::Get().GetEnemyB() );
		}
	}
	for (int i = 0; i < EnemyListC.size(); ++i)
	{
		if (!EnemyListC[i].isDead)
		{
			SpriteManager::Get().GetEnemyB().SetPosition( EnemyListC[i].x, EnemyListC[i].y );
			window.Draw( SpriteManager::Get().GetEnemyB() );
		}
	}
	for (int i = 0; i < EnemyListD.size(); ++i)
	{
		if (!EnemyListD[i].isDead)
		{
			SpriteManager::Get().GetEnemyC().SetPosition( EnemyListD[i].x, EnemyListD[i].y );
			window.Draw( SpriteManager::Get().GetEnemyC() );
		}
	}
	for (int i = 0; i < EnemyListE.size(); ++i)
	{
		if (!EnemyListE[i].isDead)
		{
			SpriteManager::Get().GetEnemyC().SetPosition( EnemyListE[i].x, EnemyListE[i].y );
			window.Draw( SpriteManager::Get().GetEnemyC() );
		}
	}

	for (int i = 0; i < UFOList.size(); ++i)
	{
		if (!UFOList[i].isDead)
		{
			SpriteManager::Get().GetUFO().SetPosition( UFOList[i].x, UFOList[i].y );
			window.Draw( SpriteManager::Get().GetUFO() );
			if (UFOPosition < 0)
			{
				UFOCanSpawn = true;
			}
		}
	}
}

void EnemyMoveDown()
{
	for (int i = 0; i < EnemyListA.size(); ++i)
	{
		EnemyListA[i].y += 25;
	}
	for (int i = 0; i < EnemyListB.size(); ++i)
	{
		EnemyListB[i].y += 25;
	}
	for (int i = 0; i < EnemyListC.size(); ++i)
	{
		EnemyListC[i].y += 25;
	}
	for (int i = 0; i < EnemyListD.size(); ++i)
	{
		EnemyListD[i].y += 25;
	}
	for (int i = 0; i < EnemyListE.size(); ++i)
	{
		EnemyListE[i].y += 25;
	}
}

void EnemyShoot(float deltaT)
{
	// Generate seed for rand():
	srand( unsigned int( time(NULL) ) );

	// Chance to spawn UFO:
	int randomUFO = rand() % 41;

	if (randomUFO == 0 && UFOCanSpawn)
	{
		Enemy UFO;
		UFO.x = 1280;
		UFO.y = 50;
		UFO.isDead = false;
		UFO.points = 1000;
		UFOList.push_back( UFO );
		UFOCanSpawn = false;
	}
	
	// Enemies shoot more frequently in higher levels:
	int randomEnemyBullet = rand() % ( 31 - (2 * (gameLevel-1)) );
	// Will crack the shits if value is above current vector size!!
	int selectEnemy = 0;
	
	if (canShoot)
	{
		switch (randomEnemyBullet)
		{
		case 0:
			selectEnemy = rand() % EnemyListA.size();
			
			if (!EnemyListA[selectEnemy].isDead)
			{
				Bullet bullet;
				bullet.x = EnemyListA[selectEnemy].x;
				bullet.y = EnemyListA[selectEnemy].y;
				bullet.isDead = false;
				EnemyBullets.push_back(bullet);
				canShoot = false;
			}
			break;
		case 1:
			selectEnemy = rand() % EnemyListB.size();
			
			if (!EnemyListB[selectEnemy].isDead)
			{
				Bullet bullet;
				bullet.x = EnemyListB[selectEnemy].x;
				bullet.y = EnemyListB[selectEnemy].y;
				bullet.isDead = false;
				EnemyBullets.push_back(bullet);
				canShoot = false;
			}
			break;
		case 2:
			selectEnemy = rand() % EnemyListC.size();
			
			if (!EnemyListC[selectEnemy].isDead)
			{
				Bullet bullet;
				bullet.x = EnemyListC[selectEnemy].x;
				bullet.y = EnemyListC[selectEnemy].y;
				bullet.isDead = false;
				EnemyBullets.push_back(bullet);
				canShoot = false;
			}
			break;
		case 3:
			selectEnemy = rand() % EnemyListD.size();
			
			if (!EnemyListD[selectEnemy].isDead)
			{
				Bullet bullet;
				bullet.x = EnemyListD[selectEnemy].x;
				bullet.y = EnemyListD[selectEnemy].y;
				bullet.isDead = false;
				EnemyBullets.push_back(bullet);
				canShoot = false;
			}
			break;
		case 4:
			selectEnemy = rand() % EnemyListE.size();
			
			if (!EnemyListE[selectEnemy].isDead)
			{
				Bullet bullet;
				bullet.x = EnemyListE[selectEnemy].x;
				bullet.y = EnemyListE[selectEnemy].y;
				bullet.isDead = false;
				EnemyBullets.push_back(bullet);
				canShoot = false;
			}
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < EnemyBullets.size(); ++i)
	{
		EnemyBullets[i].y += 400 * deltaT;
	}

	if (EnemyBulletTimer <= 0)
	{
		canShoot = true;
		EnemyBulletTimer = 100;
	}

	--EnemyBulletTimer * deltaT;
}

int EnemyCheckColumn(EnemyList &EnemyListA, 
	EnemyList &EnemyListB, 
	EnemyList &EnemyListC, 
	EnemyList &EnemyListD, 
	EnemyList &EnemyListE,
	bool &enemyMoveRight)
{
	for (int i = 0; i < 11; ++i)
	{
		if (enemyMoveRight)
		{
			// Check from the right most column
			if (!EnemyListA[10-i].isDead ||
				!EnemyListB[10-i].isDead ||
				!EnemyListC[10-i].isDead ||
				!EnemyListD[10-i].isDead ||
				!EnemyListE[10-i].isDead)
			{
				return 10-i;
			}
		}
		else if (!enemyMoveRight)
		{
			// Check from the left most column
			if (!EnemyListA[i].isDead ||
				!EnemyListB[i].isDead ||
				!EnemyListC[i].isDead ||
				!EnemyListD[i].isDead ||
				!EnemyListE[i].isDead)
			{
				return i;
			}
		}
	}
	return 0;
}

int EnemyCheckRow(EnemyList &EnemyListA, 
	EnemyList &EnemyListB, 
	EnemyList &EnemyListC, 
	EnemyList &EnemyListD, 
	EnemyList &EnemyListE)
{
	// Check from the bottom first:
	for (int i = 0; i < EnemyListE.size(); ++i)
	{
		if (!EnemyListE[i].isDead)
		{
			return 5;
		}
	}
	for (int i = 0; i < EnemyListD.size(); ++i)
	{
		if (!EnemyListD[i].isDead)
		{
			return 4;
		}
	}
	for (int i = 0; i < EnemyListC.size(); ++i)
	{
		if (!EnemyListC[i].isDead)
		{
			return 3;
		}
	}
	for (int i = 0; i < EnemyListB.size(); ++i)
	{
		if (!EnemyListB[i].isDead)
		{
			return 2;
		}
	}
	for (int i = 0; i < EnemyListA.size(); ++i)
	{
		if (!EnemyListA[i].isDead)
		{
			return 1;
		}
	}
}

bool AllEnemiesDead(EnemyList &EnemyListA, 
	EnemyList &EnemyListB, 
	EnemyList &EnemyListC, 
	EnemyList &EnemyListD, 
	EnemyList &EnemyListE)
{
	for (int i = 0; i < EnemyListA.size(); ++i)
	{
		if (!EnemyListA[i].isDead)
		{
			return false;
		}
	}
	for (int i = 0; i < EnemyListB.size(); ++i)
	{
		if (!EnemyListB[i].isDead)
		{
			return false;
		}
	}
	for (int i = 0; i < EnemyListC.size(); ++i)
	{
		if (!EnemyListC[i].isDead)
		{
			return false;
		}
	}
	for (int i = 0; i < EnemyListD.size(); ++i)
	{
		if (!EnemyListD[i].isDead)
		{
			return false;
		}
	}
	for (int i = 0; i < EnemyListE.size(); ++i)
	{
		if (!EnemyListE[i].isDead)
		{
			return false;
		}
	}
	return true;
}

bool EnemiesReachedTheHorizon(EnemyList &EnemyListA, 
	EnemyList &EnemyListB, 
	EnemyList &EnemyListC, 
	EnemyList &EnemyListD, 
	EnemyList &EnemyListE,
	int playerY)
{
	for (int i = 0; i < EnemyListA.size(); ++i)
	{
		if (!EnemyListA[i].isDead && (EnemyListA[i].y+16 > playerY-12))	// Bottom of enemy, top of player
		{
			return true;
		}
	}
	for (int i = 0; i < EnemyListB.size(); ++i)
	{
		if (!EnemyListB[i].isDead && (EnemyListB[i].y+16 > playerY-12))
		{
			return true;
		}
	}
	for (int i = 0; i < EnemyListC.size(); ++i)
	{
		if (!EnemyListC[i].isDead && (EnemyListC[i].y+16 > playerY-12))
		{
			return true;
		}
	}
	for (int i = 0; i < EnemyListD.size(); ++i)
	{
		if (!EnemyListD[i].isDead && (EnemyListD[i].y+16 > playerY-12))
		{
			return true;
		}
	}
	for (int i = 0; i < EnemyListE.size(); ++i)
	{
		if (!EnemyListE[i].isDead && (EnemyListE[i].y+16 > playerY-12))
		{
			return true;
		}
	}
	return false;
}