#include "game.h"
#include "surface.h"
#include "template.h"
#include "backround.h"
//#include "dragon.h"
#include "game_character.h"
#include <cstdio> //printf
#include <SDL.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//health bar
//score
//lives
//dupa ce colectezi 5 chei se dechide usa si te teleportezi sus sa l omori pe ala


namespace Tmpl8
{
	
	// Initialize the application

	void Game::Init()
	{
		
	}

	// Close down application

	void Game::Shutdown()
	{
	}
	static Sprite rotatingGun(new Surface("assets/aagun.tga"), 36);
	//static Sprite Dragon1(new Surface("dragon1.png"), 1);
	//static Sprite Dragon2(new Surface("dragon2.png"), 1);
	static int frame = 0;
	//int daca = 1;
	//int poz = 150;
	// Main application tick function

	void Game::Tick(float deltaTime)
	{
		screen->Clear(0x0074bd);
		Snow snow;
		Display display;
		Character character;
		snow.initialize_flakes();
		snow.draw_flakes(screen, deltaTime);
		snow.movement_flakes();
		display.display_ground(screen);
		display.display_woodsign(screen);
		character.Movement(screen);
		
		//if (daca == 1)
		//{
			//Dragon1.DrawScaled(poz, 110, 87, 87, screen);
		//}

		rotatingGun.SetFrame(frame);
		rotatingGun.Draw(screen, 100, 100);
		if (++frame == 36) frame = 0;
		
	}


		//theSprite.SetFrame(6);
		//theSprite.Draw(screen, 30, 30);
		// print something in the graphics window
		//creen->Print("hello world", 2, 2, 0xffffff);
		// print something to the text window
		//printf("this goes to the console window.\n");
		
	
};