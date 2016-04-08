#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"

BulletList PlayerBullets;
BulletList EnemyBullets;

bool bulletCanBeFired = true;

void UpdateBullets(RenderWindow &window, float deltaT)
{
	if (window.GetInput().IsKeyDown(Key::Space) && bulletCanBeFired)
	{ 
		Bullet playerBullet;
		playerBullet.x = m_player.x;
		playerBullet.y = m_player.y-12;		// Fires from the tip of the ship
		playerBullet.isDead = false;
		PlayerBullets.push_back(playerBullet);
		
		bulletCanBeFired = false;
	}
	
	if (PlayerBullets.empty())
	{
		bulletCanBeFired = true;
	}

	// Bullet can only be fired once until it collides or goes off screen
	PlayerBullets.erase(std::remove_if(PlayerBullets.begin(), PlayerBullets.end(), PlayerBulletOffScreen), PlayerBullets.end());
	PlayerBullets.erase(std::remove_if(PlayerBullets.begin(), PlayerBullets.end(), BulletIsDead), PlayerBullets.end());

	EnemyBullets.erase(std::remove_if(EnemyBullets.begin(), EnemyBullets.end(), EnemyBulletOffScreen), EnemyBullets.end());
	EnemyBullets.erase(std::remove_if(EnemyBullets.begin(), EnemyBullets.end(), BulletIsDead), EnemyBullets.end());

	for (int i = 0; i < PlayerBullets.size(); ++i)
	{
		PlayerBullets[i].y -= 600 * deltaT;
	}
}

void RenderBullets(RenderWindow &window)
{
	for(int i = 0; i < PlayerBullets.size(); ++i)
	{
		SpriteManager::Get().GetPlayerBullet().SetPosition( PlayerBullets[i].x, PlayerBullets[i].y );
		window.Draw( SpriteManager::Get().GetPlayerBullet() );
	}
	for(int i = 0; i < EnemyBullets.size(); ++i)
	{
		int enemyBulletSprite = rand() % 2;

		switch (enemyBulletSprite)
		{
		case 0:
			SpriteManager::Get().GetEnemyBulletA().SetPosition( EnemyBullets[i].x, EnemyBullets[i].y );
			window.Draw( SpriteManager::Get().GetEnemyBulletA() );
			break;
		case 1:
			SpriteManager::Get().GetEnemyBulletB().SetPosition( EnemyBullets[i].x, EnemyBullets[i].y );
			window.Draw( SpriteManager::Get().GetEnemyBulletB() );
			break;
		default:
			break;
		}
	}
}

bool PlayerBulletOffScreen(Bullet &bullet)
{
	return (bullet.y < 0);
}

bool EnemyBulletOffScreen(Bullet &bullet)
{
	return (bullet.y > 720);
}

bool BulletIsDead(Bullet &bullet)
{
	return (bullet.isDead);
}