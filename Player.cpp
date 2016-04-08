#include "Player.h"
#include "Bullet.h"

Player m_player;

void CreatePlayer()
{
	m_player.x = 640;
	m_player.y = 600;
	m_player.playerScore = 0;
	m_player.lives = 3;
	m_player.gameOver = false;
}

void UpdatePlayer(RenderWindow &window, float deltaT)
{
	// Player can move left and right:
	if (window.GetInput().IsKeyDown(Key::Left))
	{ 
		m_player.x -= 250 * deltaT;
	} 
	if (window.GetInput().IsKeyDown(Key::Right))
	{ 
		m_player.x += 250 * deltaT;
	} 

	// Set boundaries for the player: 
	if (m_player.x < 160)
	{ 
		m_player.x = 160;
	}
	if (m_player.x > 1120) 
	{ 
		m_player.x = 1120;
	}

	SpriteManager::Get().GetPlayer().SetPosition(m_player.x, m_player.y);
}

void RenderPlayer(RenderWindow &window)
{
	window.Draw( SpriteManager::Get().GetPlayer() );
}