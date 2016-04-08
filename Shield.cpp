#include <iostream>

#include "Shield.h"

ShieldList ShieldListA;
ShieldList ShieldListB;
ShieldList ShieldListC;
ShieldList ShieldListD;

void CreateShields()
{
	for (int i = 0; i < 3; ++i)
	{
		Shield shieldA;
		shieldA.x = 300;
		shieldA.y = 500 + (i * 20);
		shieldA.isDead = false;
		shieldA.durability = 5;
		ShieldListA.push_back( shieldA );

		Shield shieldB;
		shieldB.x = 500;
		shieldB.y = 500 + (i * 20);
		shieldB.isDead = false;
		shieldB.durability = 5;
		ShieldListB.push_back( shieldB );

		Shield shieldC;
		shieldC.x = 700;
		shieldC.y = 500 + (i * 20);
		shieldC.isDead = false;
		shieldC.durability = 5;
		ShieldListC.push_back( shieldC );

		Shield shieldD;
		shieldD.x = 900;
		shieldD.y = 500 + (i * 20);
		shieldD.isDead = false;
		shieldD.durability = 5;
		ShieldListD.push_back( shieldD );
	}
}

void UpdateShields(float deltaT)
{
	// If shield is shot too many times it is destroyed:
	for (int i = 0; i < ShieldListA.size(); ++i)
	{
		if (ShieldListA[i].durability == 0)
		{
			ShieldListA[i].isDead = true;
		}
	}
	for (int i = 0; i < ShieldListB.size(); ++i)
	{
		if (ShieldListB[i].durability == 0)
		{
			ShieldListB[i].isDead = true;
		}
	}
	for (int i = 0; i < ShieldListC.size(); ++i)
	{
		if (ShieldListC[i].durability == 0)
		{
			ShieldListC[i].isDead = true;
		}
	}
	for (int i = 0; i < ShieldListD.size(); ++i)
	{
		if (ShieldListD[i].durability == 0)
		{
			ShieldListD[i].isDead = true;
		}
	}
}

void RenderShields(RenderWindow &window)
{
	// Draw first column of shields
	for (int i = 0; i < ShieldListA.size(); ++i)
	{
		switch (ShieldListA[i].durability)
		{
			case 5:
				SpriteManager::Get().GetShieldA().SetPosition( ShieldListA[i].x, ShieldListA[i].y );
				window.Draw( SpriteManager::Get().GetShieldA() );
				break;
			case 4:
				SpriteManager::Get().GetShieldB().SetPosition( ShieldListA[i].x, ShieldListA[i].y );
				window.Draw( SpriteManager::Get().GetShieldB() );
				break;
			case 3:
				SpriteManager::Get().GetShieldC().SetPosition( ShieldListA[i].x, ShieldListA[i].y );
				window.Draw( SpriteManager::Get().GetShieldC() );
				break;
			case 2:
				SpriteManager::Get().GetShieldD().SetPosition( ShieldListA[i].x, ShieldListA[i].y );
				window.Draw( SpriteManager::Get().GetShieldD() );
				break;
			case 1:
				SpriteManager::Get().GetShieldE().SetPosition( ShieldListA[i].x, ShieldListA[i].y );
				window.Draw( SpriteManager::Get().GetShieldE() );
				break;
			default:
				break;
		}
	}

	// Draw second column of shields
	for (int i = 0; i < ShieldListB.size(); ++i)
	{
		switch (ShieldListB[i].durability)
		{
			case 5:
				SpriteManager::Get().GetShieldA().SetPosition( ShieldListB[i].x, ShieldListB[i].y );
				window.Draw( SpriteManager::Get().GetShieldA() );
				break;
			case 4:
				SpriteManager::Get().GetShieldB().SetPosition( ShieldListB[i].x, ShieldListB[i].y );
				window.Draw( SpriteManager::Get().GetShieldB() );
				break;
			case 3:
				SpriteManager::Get().GetShieldC().SetPosition( ShieldListB[i].x, ShieldListB[i].y );
				window.Draw( SpriteManager::Get().GetShieldC() );
				break;
			case 2:
				SpriteManager::Get().GetShieldD().SetPosition( ShieldListB[i].x, ShieldListB[i].y );
				window.Draw( SpriteManager::Get().GetShieldD() );
				break;
			case 1:
				SpriteManager::Get().GetShieldE().SetPosition( ShieldListB[i].x, ShieldListB[i].y );
				window.Draw( SpriteManager::Get().GetShieldE() );
				break;
			default:
				break;
		}
	}

	// Draw third column of shields
	for (int i = 0; i < ShieldListC.size(); ++i)
	{
		switch (ShieldListC[i].durability)
		{
			case 5:
				SpriteManager::Get().GetShieldA().SetPosition( ShieldListC[i].x, ShieldListC[i].y );
				window.Draw( SpriteManager::Get().GetShieldA() );
				break;
			case 4:
				SpriteManager::Get().GetShieldB().SetPosition( ShieldListC[i].x, ShieldListC[i].y );
				window.Draw( SpriteManager::Get().GetShieldB() );
				break;
			case 3:
				SpriteManager::Get().GetShieldC().SetPosition( ShieldListC[i].x, ShieldListC[i].y );
				window.Draw( SpriteManager::Get().GetShieldC() );
				break;
			case 2:
				SpriteManager::Get().GetShieldD().SetPosition( ShieldListC[i].x, ShieldListC[i].y );
				window.Draw( SpriteManager::Get().GetShieldD() );
				break;
			case 1:
				SpriteManager::Get().GetShieldE().SetPosition( ShieldListC[i].x, ShieldListC[i].y );
				window.Draw( SpriteManager::Get().GetShieldE() );
				break;
			default:
				break;
		}
	}

	// Draw fourth column of shields
	for (int i = 0; i < ShieldListD.size(); ++i)
	{
		switch (ShieldListD[i].durability)
		{
			case 5:
				SpriteManager::Get().GetShieldA().SetPosition( ShieldListD[i].x, ShieldListD[i].y );
				window.Draw( SpriteManager::Get().GetShieldA() );
				break;
			case 4:
				SpriteManager::Get().GetShieldB().SetPosition( ShieldListD[i].x, ShieldListD[i].y );
				window.Draw( SpriteManager::Get().GetShieldB() );
				break;
			case 3:
				SpriteManager::Get().GetShieldC().SetPosition( ShieldListD[i].x, ShieldListD[i].y );
				window.Draw( SpriteManager::Get().GetShieldC() );
				break;
			case 2:
				SpriteManager::Get().GetShieldD().SetPosition( ShieldListD[i].x, ShieldListD[i].y );
				window.Draw( SpriteManager::Get().GetShieldD() );
				break;
			case 1:
				SpriteManager::Get().GetShieldE().SetPosition( ShieldListD[i].x, ShieldListD[i].y );
				window.Draw( SpriteManager::Get().GetShieldE() );
				break;
			default:
				break;
		}
	}
}