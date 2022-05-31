#include "game.h"
#include "surface.h"
#include "template.h"
#include "backround.h"
#include "dragon.h"
#include "GameCharacter.h"
#include "lives.h"
#include <cstdio> //printf
#include <SDL.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

namespace Tmpl8
{
	Snow snow;
	Display display;
	Character character;
	Dragon dragon;
	Lives lives;
	HealthBar healthbar;

	static Sprite GameOver(new Surface("gameoverTR.png"), 1);
	static Sprite WinGame(new Surface("youwin.png"), 1);
	
	bool gameOver = false;
	bool win = true;

	// Initialize the application

	void Game::Init()
	{
		Snow snow;
		snow.initializeFlakes();
		
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
			display.displayGround(screen);
			display.displayWoodsign(screen);
			display.displayChBar(screen);
			display.displayDrBar(screen);
			//snowing effect
			snow.drawFlakes(screen, deltaTime);
			snow.movementFlakes();
			
			character.Movement(screen);
			dragon.animate_dragon(screen, deltaTime);
			lives.hitCharacter();
			lives.hitDragon();
			healthbar.cHealthBarUpdate(screen, cLivesCount);
			healthbar.dHealthBarUpdate(screen, dLivesCount);

			if (lives.dLivesNr() < 1)
			{
				dragon.dead_dragon_animation(screen);
				if(finishanimation)
				{
					gameOver = true;
					win = true;
				}
			}
			if (lives.cLivesNr() < 1)
			{
				if (finishFinalBombAnimation)
				{
					gameOver = true;
					win = false;
				}
			}
		}
	else
		{
			if (win)
			{
				WinGame.DrawScaled(180, 100, 360, 170, screen);
				screen->Print("PRESS ENTER TO PLAY AGAIN", 300, 300, 0xffffff);
				snow.drawFlakes(screen, deltaTime);
				snow.movementFlakes();
				if (GetAsyncKeyState(VK_RETURN))
				{   //game reset
					gameOver = false;
					cLivesCount = 3;
					dLivesCount = 6;
					alive = true;
					Ydragon = 40;
					leftToRight = true;
				}
			}
			else
			{   
				GameOver.DrawScaled(180, 100, 440, 170, screen);
				screen->Print("PRESS ENTER TO PLAY AGAIN", 300, 330, 0xffffff);
				snow.drawFlakes(screen, deltaTime);
				snow.movementFlakes();
				if (GetAsyncKeyState(VK_RETURN))
				{   //game reset
					gameOver = false;
					cLivesCount = 3;
					dLivesCount = 6;
					alive = true;
					Ydragon = 40;
					leftToRight = true;
				}
			}

		}
	}
	

		//theSprite.SetFrame(6);
		//theSprite.Draw(screen, 30, 30);
		// print something in the graphics window
		//screen->Print("hello world", 2, 2, 0xffffff);
		// print something to the text window
		//printf("this goes to the console window.\n");
		
	
};