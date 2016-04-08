#ifndef COLLISION_H
#define COLLISION_H

#include <vector>

struct CollisionBox
{
	float top;
	float left;
	float bottom;
	float right;

	// player 26 width, 20 low, 12 high
	// playerBullet 6 width, 11 height
	// enemyA 16 width, 16 height (from center)
	// enemyB 22 width, 16 height
	// enemyC 24 width, 16 height
	// enemyBullet 6 width, 12 height
	// UFO 48 width, 21 height
	// shield 32 width, 4 height
};

// NEW VECTOR DEFINITION:
typedef std::vector<CollisionBox> CollisionBoxList;

extern CollisionBoxList CollisionBoxListPlayer;
extern CollisionBoxList CollisionBoxListEnemyA;
extern CollisionBoxList CollisionBoxListEnemyB;
extern CollisionBoxList CollisionBoxListEnemyC;
extern CollisionBoxList CollisionBoxListEnemyD;
extern CollisionBoxList CollisionBoxListEnemyE;
extern CollisionBoxList CollisionBoxListUFO;
extern CollisionBoxList CollisionBoxListPlayerBullets;
extern CollisionBoxList CollisionBoxListEnemyBullets;
extern CollisionBoxList CollisionBoxListShieldA;
extern CollisionBoxList CollisionBoxListShieldB;
extern CollisionBoxList CollisionBoxListShieldC;
extern CollisionBoxList CollisionBoxListShieldD;

// FUNCTIONS:
bool AreColliding( CollisionBox &box1, CollisionBox &box2 );

void CheckCollision();

#endif // COLLISION_H