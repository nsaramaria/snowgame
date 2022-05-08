#include "game.h"
#include "surface.h"
#include "template.h"
#include "backround.h"
#include "dragon.h"
//#include "bomb.h"
#include "game_character.h"
#include "Lives.h"
#include <cstdio> //printf
#include <SDL.h>
#include <string>
#include <cstdlib>
#include <ctime>
//using namespace std;

namespace Tmpl8
{
	
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
	
	//int var = 1;

	// Main application tick function

	void Game::Tick(float deltaTime)
	{
		screen->Clear(0x0074bd);
		Snow snow;
		Display display;
		Character character;
		Dragon dragon;
		Lives lives;
		HealthBar healthbar;
		//snow.initialize_flakes();
		snow.draw_flakes(screen, deltaTime);
		snow.movement_flakes();
		display.display_ground(screen);
		display.display_woodsign(screen);
		character.Movement(screen);
		dragon.animate_dragon(screen, deltaTime);
		//bomb.throw_bomb(Xdragon, Ydragon+100, screen);
		//lives.HitCharacter();
		healthbar.healthBar_update(screen, 1);
		
		
	}


		//theSprite.SetFrame(6);
		//theSprite.Draw(screen, 30, 30);
		// print something in the graphics window
		//screen->Print("hello world", 2, 2, 0xffffff);
		// print something to the text window
		//printf("this goes to the console window.\n");
		
	
};