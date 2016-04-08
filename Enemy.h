#ifndef ENEMY_H
#define ENEMY_H

#include <vector>

#include "SpriteManager.h"
#include "Object.h"

struct Enemy : public Object
{
	int points;
};

// NEW VECTOR DEFINITION:
typedef std::vector<Enemy> EnemyList;

extern EnemyList EnemyListA;
extern EnemyList EnemyListB;
extern EnemyList EnemyListC;
extern EnemyList EnemyListD;
extern EnemyList EnemyListE;
extern EnemyList UFOList;

// VARIABLES:
extern bool enemyMoveRight;
extern bool UFOCanSpawn;
extern int UFOPosition;
extern int gameLevel;
extern int enemySpeed;
extern int edgeCounter;
extern int whichEnemyColumnIsAlive;
extern int whichEnemyRowIsAlive;

// FUNCTIONS:
void CreateEnemies(int gameLevel);

void UpdateEnemies(float deltaT);
void RenderEnemies(RenderWindow &window);

void EnemyMoveDown();
void EnemyShoot(float deltaT);

int EnemyCheckColumn(EnemyList &EnemyListA, 
	EnemyList &EnemyListB, 
	EnemyList &EnemyListC, 
	EnemyList &EnemyListD, 
	EnemyList &EnemyListE,
	bool &enemyMoveRight);
int EnemyCheckRow(EnemyList &EnemyListA, 
	EnemyList &EnemyListB, 
	EnemyList &EnemyListC, 
	EnemyList &EnemyListD, 
	EnemyList &EnemyListE);
bool AllEnemiesDead(EnemyList &EnemyListA, 
	EnemyList &EnemyListB, 
	EnemyList &EnemyListC, 
	EnemyList &EnemyListD, 
	EnemyList &EnemyListE);
bool EnemiesReachedTheHorizon(EnemyList &EnemyListA, 
	EnemyList &EnemyListB, 
	EnemyList &EnemyListC, 
	EnemyList &EnemyListD, 
	EnemyList &EnemyListE,
	int playerY);

#endif // ENEMY_H