#include "SFML/Graphics.hpp" 
#include "cmath" 
#include "kf/kf_log.h" 
#include "qgf2d/system.h"
#include "qgf2d/anim.h"

#include <fstream>

#include "SpriteManager.h"
#include "GameStateManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Shield.h"
#include "Collision.h"

using namespace std; 
using namespace qgf; 
using namespace kf; 
using namespace sf; 

void Initialise(int gameLevel)
{
	CreatePlayer();
	CreateEnemies(gameLevel);
	CreateShields();
}

void Update(RenderWindow &window, float deltaT)
{
	// Update player/enemy positions, deaths, etc.
	UpdatePlayer(window, deltaT);
	UpdateEnemies(deltaT);
	UpdateBullets(window, deltaT);
	UpdateShields(deltaT);
	CheckCollision();
	EnemyShoot(deltaT);
}

void IncreaseLevel()
{
	if ( AllEnemiesDead(EnemyListA, EnemyListB, EnemyListC, EnemyListD, EnemyListE) )
	{
		// Increase game level:
		++gameLevel;
				
		// Refresh enemy lists:
		EnemyListA.swap( EnemyList() );
		EnemyListB.swap( EnemyList() );
		EnemyListC.swap( EnemyList() );
		EnemyListD.swap( EnemyList() );
		EnemyListE.swap( EnemyList() );

		// Reset enemy speed:
		enemySpeed = 20 + ((gameLevel - 1) * 20);
				
		// Destroy shields at level 5:
		if (gameLevel == 5)
		{
			for (int i = 0; i < ShieldListA.size(); ++i)
			{
				ShieldListA[i].durability = 0;
				ShieldListA[i].isDead = true;
			}
			for (int i = 0; i < ShieldListB.size(); ++i)
			{
				ShieldListB[i].durability = 0;
				ShieldListB[i].isDead = true;
			}
			for (int i = 0; i < ShieldListC.size(); ++i)
			{
				ShieldListC[i].durability = 0;
				ShieldListC[i].isDead = true;
			}
			for (int i = 0; i < ShieldListD.size(); ++i)
			{
				ShieldListD[i].durability = 0;
				ShieldListD[i].isDead = true;
			}
		}
				
		CreateEnemies(gameLevel);
	}
}

void Render(RenderWindow &window, bool &pauseMenu, bool &gameOver, Drawable &gLevel, Drawable &pScore, Drawable &hScore, Drawable &numLives)
{
	// Draw shit to the screen
	window.Clear();
	window.Draw(Shape::Rectangle(0,0,1280,720,Color::Black));
	RenderPlayer(window);
	RenderEnemies(window);
	RenderBullets(window);
	RenderShields(window);
	window.Draw(gLevel);
	window.Draw(pScore);
	window.Draw(hScore);
	window.Draw(numLives);
	if (pauseMenu)
	{
		window.Draw( SpriteManager::Get().GetPauseScreen() );
	}
	if (gameOver)
	{
		window.Draw( SpriteManager::Get().GetHighScoreScreen() );
		window.Draw(pScore);
		window.Draw(hScore);
	}
	window.Display();
}

int main() 
{ 
    // This will initialise the QGF2D folders: 
    initDirectory(); 
  
    // Set up logging: 
    Log::getDefault().addCout(); 
    Log::getDefault().addFile("SpaceInvaders.log"); 
    kf_log("SUPEISU INVEIDASUUUUUUUUUUUUUUUUUUUUUUUUUUUDESUDESUDESU");

	// Input from external files:
	ifstream resolutionFile("data/resolution.txt");
	int screenWidth = 1280, screenHeight = 720;

	if ( !resolutionFile.fail() )
	{
		resolutionFile >> screenWidth;
		resolutionFile >> screenHeight;
	}

	ifstream highScoreFileRead("data/highScore.txt");
	int highScore;

	if ( !highScoreFileRead.fail() )
	{
		highScoreFileRead >> highScore;
	}

    // Set up window resolution and title: 
    RenderWindow window(VideoMode(screenWidth, screenHeight, 32), "Space Invaders: Inspired by Sony destroying petty Microsoft");

    // Creating our sprite objects: 
	SpriteManager::Get().LoadSprites();

	// Create animations for the enemies:
	Anim enemyAAnim(&SpriteManager::Get().GetEnemyA(),0,0,64,64,2,1);
	enemyAAnim.addSequence("move",0,2,1,true);
	Anim enemyBAnim(&SpriteManager::Get().GetEnemyB(),0,64,64,64,2,1);
	enemyBAnim.addSequence("move",0,2,1,true);
	Anim enemyCAnim(&SpriteManager::Get().GetEnemyC(),0,128,64,64,2,1);
	enemyCAnim.addSequence("move",0,2,1,true);

	bool pauseMenu = false;

	// Set game state to the title screen:
	stateStack.push(Title);

	while (window.IsOpened()) 
	{  
		Event ev; 
		while (window.GetEvent(ev)) 
		{ 
			if ((ev.Type == Event::Closed) || ((ev.Type == Event::KeyPressed) && (ev.Key.Code == Key::Escape))) 
			{ 
			    window.Close(); 
			    break; 
			} 
		}
		
		// Text for score and lives:
		std::stringstream gameLevelString;
		gameLevelString << "Level: " << gameLevel;
		char gStr[256];
		gameLevelString.getline(gStr, 256);
		String gLevel;
		gLevel.SetPosition(200, 610);
		gLevel.SetText(gStr);
		gLevel.SetSize(24);
		
		std::stringstream scoreString;
		scoreString << "Your score: " << m_player.playerScore;
		char pStr[256];
		scoreString.getline(pStr, 256);
		String pScore;
		pScore.SetPosition(200, 650);
		pScore.SetText(pStr);
		pScore.SetSize(24);

		std::stringstream highScoreString;
		highScoreString << "High Score: " << highScore;
		char hStr[256];
		highScoreString.getline(hStr, 256);
		String hScore;
		hScore.SetPosition(530, 650);
		hScore.SetText(hStr);
		hScore.SetSize(24);

		std::stringstream livesString;
		livesString << "Lives: " << m_player.lives;
		char lStr[256];
		livesString.getline(lStr, 256);
		String numLives;
		numLives.SetPosition(980, 650);
		numLives.SetText(lStr);
		numLives.SetSize(24);

		float deltaT = window.GetFrameTime();
		
		GameState currentState = stateStack.top();

		switch (currentState)
		{
		case Title:
			window.Clear();
			window.Draw( SpriteManager::Get().GetTitleScreen() );
			window.Display();
			if (window.GetInput().IsKeyDown(Key::Return))
			{
				stateStack.push(Game);
				Initialise(gameLevel);
				
				// Reset all the values for game restart:
				pScore.SetPosition(200, 650);
				hScore.SetPosition(530, 650);
				gameLevel = 1;
				enemySpeed = 2000;
			}
			break;
		case Game:
			// Enemy animations:
			enemyAAnim.play("move",false);
			enemyAAnim.update(deltaT);
			enemyBAnim.play("move",false);
			enemyBAnim.update(deltaT);
			enemyCAnim.play("move",false);
			enemyCAnim.update(deltaT);

			Update(window, deltaT);
			Render(window, pauseMenu, m_player.gameOver, gLevel, pScore, hScore, numLives);
			IncreaseLevel();

			// Replace high score if current score is higher:
			if (m_player.playerScore > highScore)
			{
				highScore = m_player.playerScore;
			}

			if (EnemiesReachedTheHorizon(EnemyListA, EnemyListB, EnemyListC, EnemyListD, EnemyListE, m_player.y) || 
				m_player.lives == 0)
			{
				m_player.gameOver = true;
				stateStack.push(HighScore);
				cout << "Game over, sucker!" << endl;
			}
			
			// Access pause menu:
			if (window.GetInput().IsKeyDown(Key::P))
			{
				stateStack.push(Pause);
				pauseMenu = true;
			}
			break;
		case Pause:
			Render(window, pauseMenu, m_player.gameOver, gLevel, pScore, hScore, numLives);
			if (window.GetInput().IsKeyDown(Key::Return))
			{
				stateStack.pop();
				pauseMenu = false;
			}
			break;
		case HighScore:
			pScore.SetPosition(380, 360);
			hScore.SetPosition(680, 360);
			Render(window, pauseMenu, m_player.gameOver, gLevel, pScore, hScore, numLives);
			
			// Refresh enemy lists:
			EnemyListA.swap( EnemyList() );
			EnemyListB.swap( EnemyList() );
			EnemyListC.swap( EnemyList() );
			EnemyListD.swap( EnemyList() );
			EnemyListE.swap( EnemyList() );
			
			if (window.GetInput().IsKeyDown(Key::Return))
			{
				stateStack.pop();
				stateStack.pop();	// Activating Game State due to Enter press?
			}
			break;
		default:
			break;
		}
    }
	return 0; 
}