#ifndef PLAYER_H
#define PLAYER_H

#include "SpriteManager.h"
#include "Object.h"

struct Player : public Object
{
	int playerScore;
	int lives;
	bool gameOver;
};

// OBJECT:
extern Player m_player;

// FUNCTIONS:
void CreatePlayer();

void UpdatePlayer(RenderWindow &window, float deltaT);
void RenderPlayer(RenderWindow &window);

#endif // PLAYER_H