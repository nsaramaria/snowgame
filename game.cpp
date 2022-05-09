#include "game.h"
#include "surface.h"
#include "template.h"
#include "backround.h"
#include "dragon.h"
#include "game_character.h"
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
		snow.initialize_flakes();
		
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
		{
			snow.draw_flakes(screen, deltaTime);
			snow.movement_flakes();
			display.display_ground(screen);
			display.display_woodsign(screen);
			display.display_ch_bar(screen);
			display.display_dr_bar(screen);
			character.Movement(screen);
			dragon.animate_dragon(screen, deltaTime);
			lives.HitCharacter();
			lives.HitDragon();
			healthbar.ChealthBar_update(screen, ClivesCount);
			healthbar.DhealthBar_update(screen, DlivesCount);
			if (lives.DLivesNr() < 6)
			{
				dragon.dead_dragon_animation(screen);
				if(finishanimation)
				{
					gameOver = true;
					win = true;
				}
			}
			if (lives.CLivesNr() < 1)
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
				snow.draw_flakes(screen, deltaTime);
				snow.movement_flakes();
				if (GetAsyncKeyState(VK_RETURN))
				{   //game reset
					gameOver = false;
					ClivesCount = 3;
					DlivesCount = 6;
					alive = true;
					Ydragon = 40;
				}
			}
			else
			{   
				GameOver.DrawScaled(180, 100, 440, 170, screen);
				screen->Print("PRESS ENTER TO PLAY AGAIN", 300, 330, 0xffffff);
				snow.draw_flakes(screen, deltaTime);
				snow.movement_flakes();
				if (GetAsyncKeyState(VK_RETURN))
				{   //game reset
					gameOver = false;
					ClivesCount = 3;
					DlivesCount = 6;
					alive = true;
					Ydragon = 40;
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