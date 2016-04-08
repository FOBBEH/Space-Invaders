#include <iostream>

#include "Collision.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Shield.h"

using std::cout;
using std::endl;

CollisionBoxList CollisionBoxListPlayer;
CollisionBoxList CollisionBoxListEnemyA;
CollisionBoxList CollisionBoxListEnemyB;
CollisionBoxList CollisionBoxListEnemyC;
CollisionBoxList CollisionBoxListEnemyD;
CollisionBoxList CollisionBoxListEnemyE;
CollisionBoxList CollisionBoxListUFO;
CollisionBoxList CollisionBoxListPlayerBullets;
CollisionBoxList CollisionBoxListEnemyBullets;
CollisionBoxList CollisionBoxListShieldA;
CollisionBoxList CollisionBoxListShieldB;
CollisionBoxList CollisionBoxListShieldC;
CollisionBoxList CollisionBoxListShieldD;

bool AreColliding( CollisionBox &box1, CollisionBox &box2 )
{
	if (box1.top > box2.bottom) return false;
	if (box2.top > box1.bottom) return false;
	if (box1.left > box2.right) return false;
	if (box2.left > box1.right) return false;

	return true;
}

void CheckCollision()
{
	// Delete vector lists:
	CollisionBoxListPlayer.swap( CollisionBoxList() );
	CollisionBoxListEnemyA.swap( CollisionBoxList() );
	CollisionBoxListEnemyB.swap( CollisionBoxList() );
	CollisionBoxListEnemyC.swap( CollisionBoxList() );
	CollisionBoxListEnemyD.swap( CollisionBoxList() );
	CollisionBoxListEnemyE.swap( CollisionBoxList() );
	CollisionBoxListUFO.swap( CollisionBoxList() );
	CollisionBoxListPlayerBullets.swap( CollisionBoxList() );
	CollisionBoxListEnemyBullets.swap( CollisionBoxList() );
	CollisionBoxListShieldA.swap( CollisionBoxList() );
	CollisionBoxListShieldB.swap( CollisionBoxList() );
	CollisionBoxListShieldC.swap( CollisionBoxList() );
	CollisionBoxListShieldD.swap( CollisionBoxList() );

	// Create collision box for player:
	for (int i = 0; i < 1; ++i)
	{
		CollisionBox playerCollision;
		playerCollision.top = m_player.y - 12;
		playerCollision.left = m_player.x - 26;
		playerCollision.bottom = m_player.y + 20;
		playerCollision.right = m_player.x + 26;
		CollisionBoxListPlayer.push_back(playerCollision);
	}

	// Create collision boxes for enemies:
	for (int i = 0; i < EnemyListA.size(); ++i)
	{
		CollisionBox enemyCollisionA;
		enemyCollisionA.top = EnemyListA[i].y - 16;
		enemyCollisionA.left = EnemyListA[i].x - 16;
		enemyCollisionA.bottom = EnemyListA[i].y + 16;
		enemyCollisionA.right = EnemyListA[i].x + 16;
		CollisionBoxListEnemyA.push_back(enemyCollisionA);
	}
	for (int i = 0; i < EnemyListB.size(); ++i)
	{
		CollisionBox enemyCollisionB;
		enemyCollisionB.top = EnemyListB[i].y - 16;
		enemyCollisionB.left = EnemyListB[i].x - 22;
		enemyCollisionB.bottom = EnemyListB[i].y + 16;
		enemyCollisionB.right = EnemyListB[i].x + 22;
		CollisionBoxListEnemyB.push_back(enemyCollisionB);
	}
	for (int i = 0; i < EnemyListC.size(); ++i)
	{
		CollisionBox enemyCollisionC;
		enemyCollisionC.top = EnemyListC[i].y - 16;
		enemyCollisionC.left = EnemyListC[i].x - 22;
		enemyCollisionC.bottom = EnemyListC[i].y + 16;
		enemyCollisionC.right = EnemyListC[i].x + 22;
		CollisionBoxListEnemyC.push_back(enemyCollisionC);
	}
	for (int i = 0; i < EnemyListD.size(); ++i)
	{
		CollisionBox enemyCollisionD;
		enemyCollisionD.top = EnemyListD[i].y - 16;
		enemyCollisionD.left = EnemyListD[i].x - 24;
		enemyCollisionD.bottom = EnemyListD[i].y + 16;
		enemyCollisionD.right = EnemyListD[i].x + 24;
		CollisionBoxListEnemyD.push_back(enemyCollisionD);
	}
	for (int i = 0; i < EnemyListE.size(); ++i)
	{
		CollisionBox enemyCollisionE;
		enemyCollisionE.top = EnemyListE[i].y - 16;
		enemyCollisionE.left = EnemyListE[i].x - 24;
		enemyCollisionE.bottom = EnemyListE[i].y + 16;
		enemyCollisionE.right = EnemyListE[i].x + 24;
		CollisionBoxListEnemyE.push_back(enemyCollisionE);
	}

	// Create collision box for UFO:
	for (int i = 0; i < UFOList.size(); ++i)
	{
		CollisionBox UFOCollision;
		UFOCollision.top = UFOList[i].y - 21;
		UFOCollision.left = UFOList[i].x - 48;
		UFOCollision.bottom = UFOList[i].y + 21;
		UFOCollision.right = UFOList[i].x + 48;
		CollisionBoxListUFO.push_back(UFOCollision);
	}

	// Create collision box for player bullets:
	for (int i = 0; i < PlayerBullets.size(); ++i)
	{
		CollisionBox playerBulletCollision;
		playerBulletCollision.top = PlayerBullets[i].y - 11;
		playerBulletCollision.left = PlayerBullets[i].x - 6;
		playerBulletCollision.bottom = PlayerBullets[i].y + 11;
		playerBulletCollision.right = PlayerBullets[i].x + 6;
		CollisionBoxListPlayerBullets.push_back(playerBulletCollision);
	}

	// Create collision box for enemy bullets:
	for (int i = 0; i < EnemyBullets.size(); ++i)
	{
		CollisionBox enemyBulletCollision;
		enemyBulletCollision.top = EnemyBullets[i].y - 11;
		enemyBulletCollision.left = EnemyBullets[i].x - 6;
		enemyBulletCollision.bottom = EnemyBullets[i].y + 11;
		enemyBulletCollision.right = EnemyBullets[i].x + 6;
		CollisionBoxListEnemyBullets.push_back(enemyBulletCollision);
	}
	
	// Create collision box for shields:
	for (int i = 0; i < ShieldListA.size(); ++i)
	{
		CollisionBox shieldCollisionA;
		shieldCollisionA.top = ShieldListA[i].y - 4;
		shieldCollisionA.left = ShieldListA[i].x - 32;
		shieldCollisionA.bottom = ShieldListA[i].y + 4;
		shieldCollisionA.right = ShieldListA[i].x + 32;
		CollisionBoxListShieldA.push_back(shieldCollisionA);
	}
	for (int i = 0; i < ShieldListB.size(); ++i)
	{
		CollisionBox shieldCollisionB;
		shieldCollisionB.top = ShieldListB[i].y - 4;
		shieldCollisionB.left = ShieldListB[i].x - 32;
		shieldCollisionB.bottom = ShieldListB[i].y + 4;
		shieldCollisionB.right = ShieldListB[i].x + 32;
		CollisionBoxListShieldB.push_back(shieldCollisionB);
	}
	for (int i = 0; i < ShieldListC.size(); ++i)
	{
		CollisionBox shieldCollisionC;
		shieldCollisionC.top = ShieldListC[i].y - 4;
		shieldCollisionC.left = ShieldListC[i].x - 32;
		shieldCollisionC.bottom = ShieldListC[i].y + 4;
		shieldCollisionC.right = ShieldListC[i].x + 32;
		CollisionBoxListShieldC.push_back(shieldCollisionC);
	}
	for (int i = 0; i < ShieldListD.size(); ++i)
	{
		CollisionBox shieldCollisionD;
		shieldCollisionD.top = ShieldListD[i].y - 4;
		shieldCollisionD.left = ShieldListD[i].x - 32;
		shieldCollisionD.bottom = ShieldListD[i].y + 4;
		shieldCollisionD.right = ShieldListD[i].x + 32;
		CollisionBoxListShieldD.push_back(shieldCollisionD);
	}

	// Check if player bullets collide with any enemies or shields:
	for (int k = 0; k < CollisionBoxListPlayerBullets.size(); ++k)
	{
		// ENEMIES:		
		for (int i = 0; i < CollisionBoxListEnemyA.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListEnemyA[i] ))
			{
				if (!EnemyListA[i].isDead)
				{
					EnemyListA[i].isDead = true;
					PlayerBullets[k].isDead = true;
					m_player.playerScore += EnemyListA[i].points;
					cout << "EnemyA is destroyed!" << endl;
				}
			}
		}
		for (int i = 0; i < CollisionBoxListEnemyB.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListEnemyB[i] ))
			{
				if (!EnemyListB[i].isDead)
				{
					EnemyListB[i].isDead = true;
					PlayerBullets[k].isDead = true;
					m_player.playerScore += EnemyListB[i].points;
					cout << "EnemyB is destroyed!" << endl;
				}
			}
		}
		for (int i = 0; i < CollisionBoxListEnemyC.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListEnemyC[i] ))
			{
				if (!EnemyListC[i].isDead)
				{
					EnemyListC[i].isDead = true;
					PlayerBullets[k].isDead = true;
					m_player.playerScore += EnemyListC[i].points;
					cout << "EnemyC is destroyed!" << endl;
				}
			}
		}
		for (int i = 0; i < CollisionBoxListEnemyD.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListEnemyD[i] ))
			{
				if (!EnemyListD[i].isDead)
				{
					EnemyListD[i].isDead = true;
					PlayerBullets[k].isDead = true;
					m_player.playerScore += EnemyListD[i].points;
					cout << "EnemyD is destroyed!" << endl;
				}
			}
		}
		for (int i = 0; i < CollisionBoxListEnemyE.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListEnemyE[i] ))
			{
				if (!EnemyListE[i].isDead)
				{
					EnemyListE[i].isDead = true;
					PlayerBullets[k].isDead = true;
					m_player.playerScore += EnemyListE[i].points;
					cout << "EnemyE is destroyed!" << endl;
				}
			}
		}

		// UFO:
		for (int i = 0; i < CollisionBoxListUFO.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListUFO[i] ))
			{
				UFOList[i].isDead = true;
				PlayerBullets[k].isDead = true;
				UFOCanSpawn = true;
				m_player.playerScore += UFOList[i].points;
				cout << "UFO is destroyed!" << endl;
			}
		}

		// SHIELDS:
		for (int i = 0; i < CollisionBoxListShieldA.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListShieldA[i] ))
			{
				if (!ShieldListA[i].isDead)
				{
					--ShieldListA[i].durability;
					PlayerBullets[k].isDead = true;
					cout << "ShieldA took damage from player!" << endl;
					if (ShieldListA[i].durability == 0)
					{
						ShieldListA[i].isDead = true;
						cout << "ShieldA is destroyed!" << endl;
					}
				}
			}
		}
		for (int i = 0; i < CollisionBoxListShieldB.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListShieldB[i] ))
			{
				if (!ShieldListB[i].isDead)
				{
					--ShieldListB[i].durability;
					PlayerBullets[k].isDead = true;
					cout << "ShieldB took damage from player!" << endl;
					if (ShieldListB[i].durability == 0)
					{
						ShieldListB[i].isDead = true;
						cout << "ShieldB is destroyed!" << endl;
					}
				}
			}
		}
		for (int i = 0; i < CollisionBoxListShieldC.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListShieldC[i] ))
			{
				if (!ShieldListC[i].isDead)
				{
					--ShieldListC[i].durability;
					PlayerBullets[k].isDead = true;
					cout << "ShieldC took damage from player!" << endl;
					if (ShieldListC[i].durability == 0)
					{
						ShieldListC[i].isDead = true;
						cout << "ShieldC is destroyed!" << endl;
					}
				}
			}
		}
		for (int i = 0; i < CollisionBoxListShieldD.size(); ++i)
		{
			if (AreColliding( CollisionBoxListPlayerBullets[k], CollisionBoxListShieldD[i] ))
			{
				if (!ShieldListD[i].isDead)
				{
					--ShieldListD[i].durability;
					PlayerBullets[k].isDead = true;
					cout << "ShieldD took damage from player!" << endl;
					if (ShieldListD[i].durability == 0)
					{
						ShieldListD[i].isDead = true;
						cout << "ShieldD is destroyed!" << endl;
					}
				}
			}
		}
	}

	// Check if enemy bullets collide with player or shields:
	for (int k = 0; k < CollisionBoxListEnemyBullets.size(); ++k)
	{
		// PLAYER:		
		for (int i = 0; i < CollisionBoxListPlayer.size(); ++i)
		{
			if (AreColliding( CollisionBoxListEnemyBullets[k], CollisionBoxListPlayer[i] ))
			{
				if (!m_player.isDead)
				{
					--m_player.lives;
					EnemyBullets[k].isDead = true;
					cout << "You lost a life!" << endl;
					if (m_player.lives == 0)
					{
						m_player.isDead = true;
						cout << "Game over!" << endl;
					}
				}
			}
		}

		// SHIELDS:
		for (int i = 0; i < CollisionBoxListShieldA.size(); ++i)
		{
			if (AreColliding( CollisionBoxListEnemyBullets[k], CollisionBoxListShieldA[i] ))
			{
				if (!ShieldListA[i].isDead)
				{
					--ShieldListA[i].durability;
					EnemyBullets[k].isDead = true;
					cout << "ShieldA took damage from enemy!" << endl;
					if (ShieldListA[i].durability == 0)
					{
						ShieldListA[i].isDead = true;
						cout << "ShieldA is destroyed!" << endl;
					}
				}
			}
		}
		for (int i = 0; i < CollisionBoxListShieldB.size(); ++i)
		{
			if (AreColliding( CollisionBoxListEnemyBullets[k], CollisionBoxListShieldB[i] ))
			{
				if (!ShieldListB[i].isDead)
				{
					--ShieldListB[i].durability;
					EnemyBullets[k].isDead = true;
					cout << "ShieldB took damage from enemy!" << endl;
					if (ShieldListB[i].durability == 0)
					{
						ShieldListB[i].isDead = true;
						cout << "ShieldB is destroyed!" << endl;
					}
				}
			}
		}
		for (int i = 0; i < CollisionBoxListShieldC.size(); ++i)
		{
			if (AreColliding( CollisionBoxListEnemyBullets[k], CollisionBoxListShieldC[i] ))
			{
				if (!ShieldListC[i].isDead)
				{
					--ShieldListC[i].durability;
					EnemyBullets[k].isDead = true;
					cout << "ShieldC took damage from enemy!" << endl;
					if (ShieldListC[i].durability == 0)
					{
						ShieldListC[i].isDead = true;
						cout << "ShieldC is destroyed!" << endl;
					}
				}
			}
		}
		for (int i = 0; i < CollisionBoxListShieldD.size(); ++i)
		{
			if (AreColliding( CollisionBoxListEnemyBullets[k], CollisionBoxListShieldD[i] ))
			{
				if (!ShieldListD[i].isDead)
				{
					--ShieldListD[i].durability;
					EnemyBullets[k].isDead = true;
					cout << "ShieldD took damage from enemy!" << endl;
					if (ShieldListD[i].durability == 0)
					{
						ShieldListD[i].isDead = true;
						cout << "ShieldD is destroyed!" << endl;
					}
				}
			}
		}
	}
}