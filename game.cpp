#include "game.h"
#include "surface.h"
#include "template.h"
#include "backround.h"
#include "dragon.h"
#include "GameCharacter.h"
#include "Entity.h"
#include "lives.h"
#include <cstdio> //printf

using namespace std;

namespace Tmpl8
{
	Snow snow;
	Display display;
	Character character;
	Dragon dragon;
	Lives lives;
	HealthBar healthbar;

	static Sprite GameOver(new Surface("assets/gameoverTR.png"), 1);
	static Sprite WinGame(new Surface("assets/youwin.png"), 1);
	
	bool gameOver = false;
	bool win = true;

	// Initialize the application

	void Game::Init()
	{
		Snow snow;
		snow.InitializeFlakes();
		finishanimation = false;
	}

	// Close down application

	void Game::Shutdown()
	{
	
	}

	// Main application tick function

	void Game::Tick(float deltaTime)
	{
		screen->Clear(0x0074bd);

		if (!gameOver)
		{   //display map
			display.DisplayGround(screen);
			display.DisplayWoodsign(screen);
			display.DisplayChBar(screen);
			display.DisplayDrBar(screen);
			//snowing effect
			snow.DrawFlakes(screen, deltaTime);
			snow.MovementFlakes();
			character.Movement(screen);
			dragon.AnimateDragon(screen, deltaTime);
			lives.HitCharacter();
			lives.HitDragon();
			healthbar.CHealthBarUpdate(screen, cLivesCount);
			healthbar.DHealthBarUpdate(screen, dLivesCount);

			if (lives.DLivesNo() < 1)
			{   
				dragon.DeadDragonAnimation(screen,deltaTime);
				if(finishanimation)
				{
					gameOver = true;
					win = true;
				}
			}
			if (lives.CLivesNo() < 1)
			{
					gameOver = true;
					win = false;
			}
		}
	else
		{
			if (win)
			{
				WinGame.DrawScaled(180, 100, 360, 170, screen);
				screen->Print("PRESS ENTER TO PLAY AGAIN", 300, 300, 0xffffff);
				snow.DrawFlakes(screen, deltaTime);
				snow.MovementFlakes();
				if (GetAsyncKeyState(VK_RETURN))
				{   //game reset
					gameOver = false;
					cLivesCount = 3;
					dLivesCount = 6;
					alive = true;
					Ydragon = 40;
					Xdragon = 350;
					leftToRight = true;
					finishanimation = false;
				}
			}
			else
			{   
				GameOver.DrawScaled(180, 100, 440, 170, screen);
				screen->Print("PRESS ENTER TO PLAY AGAIN", 300, 330, 0xffffff);
				snow.DrawFlakes(screen, deltaTime);
				snow.MovementFlakes();
				if (GetAsyncKeyState(VK_RETURN))
				{   //game reset
					gameOver = false;
					cLivesCount = 3;
					dLivesCount = 6;
					alive = true;
					Ydragon = 40;
					Xdragon = 350;
					leftToRight = true;
					finishanimation = false;
				}
			}
		}
	}
};