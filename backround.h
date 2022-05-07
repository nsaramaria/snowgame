#pragma once
#include <iostream>
#include "surface.h"
#include "game.h"
#include "template.h"
#include <SDL.h>
#include <cstdio> //printf
#include <string>
#include <Windows.h>
#include <thread>

const int Total_flakes = 200;
const int layer = 3;
float flakesX[700];
float flakesY[700];
int flakes_layer[700];
int fcolor;
float speed;
namespace Tmpl8 {
	class Surface;
	static Sprite SnowBlockInit(new Surface("1.png"), 1);
	static Sprite SnowBlockMid(new Surface("2.png"), 1);
	static Sprite SnowBlockFin(new Surface("3.png"), 1);

	static Sprite SnowBlockUpInit(new Surface("14.png"), 1);
	static Sprite SnowBlockUpMid(new Surface("15.png"), 1);
	static Sprite SnowBlockUpFin(new Surface("16.png"), 1);

	static Sprite WoodSign(new Surface("Sign_1.png"), 1);

	class Snow
	{
	public:
		void initialize_flakes()
		{
			for (int i = 0; i < Total_flakes; i++)
			{
				flakesX[i] = Rand(ScreenWidth);
				flakesY[i] = Rand(ScreenHeight);
				flakes_layer[i] = Rand(layer);
			}
		}
		void draw_flakes(Surface* screen, float deltaTime)
		{
			//making 3 different snowfleaks types with different form , color and speed
			for (int i = 0; i < Total_flakes; i++)
			{
				if (flakes_layer[i] == 0)
				{
					speed = 0.1f * deltaTime;
					fcolor = 0x4cbfe0;
					//circular snowfleaks
					screen->Plot(flakesX[i], flakesY[i], fcolor);
					screen->Plot(flakesX[i] + 1, flakesY[i], fcolor);
					screen->Plot(flakesX[i] + 1, flakesY[i] + 1, fcolor);
					screen->Plot(flakesX[i], flakesY[i] + 1, fcolor);
				}
				if (flakes_layer[i] == 1)
				{
					speed = 0.2f * deltaTime;
					fcolor = 0xcae9ff;
					//star snowfleaks
					screen->Plot(flakesX[i], flakesY[i], fcolor);
					screen->Plot(flakesX[i] + 1, flakesY[i], fcolor);
					screen->Plot(flakesX[i] + 2, flakesY[i], fcolor);
					screen->Plot(flakesX[i] + 3, flakesY[i], fcolor);
					screen->Plot(flakesX[i], flakesY[i] + 1, fcolor);
					screen->Plot(flakesX[i], flakesY[i] + 2, fcolor);
					screen->Plot(flakesX[i], flakesY[i] + 3, fcolor);
					screen->Plot(flakesX[i] - 1, flakesY[i], fcolor);
					screen->Plot(flakesX[i] - 2, flakesY[i], fcolor);
					screen->Plot(flakesX[i] - 3, flakesY[i], fcolor);
					screen->Plot(flakesX[i], flakesY[i] - 1, fcolor);
					screen->Plot(flakesX[i], flakesY[i] - 2, fcolor);
					screen->Plot(flakesX[i], flakesY[i] - 3, fcolor);
				}
				if (flakes_layer[i] == 2)
				{
					speed = 0.3f * deltaTime;
					fcolor = 0x8fcbff;
					//circular snowfleaks
					screen->Plot(flakesX[i], flakesY[i], fcolor);
					screen->Plot(flakesX[i] + 1, flakesY[i], fcolor);
					screen->Plot(flakesX[i] + 1, flakesY[i] + 1, fcolor);
					screen->Plot(flakesX[i], flakesY[i] + 1, fcolor);
				}
			}

		}
		void movement_flakes()
		{
			for ( int i = 0; i < Total_flakes; i++)
			{
				flakesY[i] += speed;

				if (flakesY[i] > ScreenHeight)
				{
					flakesX[i] = Rand(ScreenWidth);
					flakesY[i] = 0.0f;
					flakes_layer[i] = Rand(layer);
				}
			}
		}
	};//class Snow

	class Display
	{
	public:

		void display_ground(Surface* screen)
		{
			//ground blocks placed on the buttom of the screen
			SnowBlockInit.DrawScaled(3, 442, 70, 70, screen);
			int placing = 70;
			for (int i = 1; i <= 10; i++)
			{
				SnowBlockMid.DrawScaled(placing, 442, 70, 70, screen);
				placing += 70;
			}
			SnowBlockFin.DrawScaled(727, 442, 70, 70, screen);
			
			//ground blocks placed on the top of the screen
			SnowBlockUpInit.DrawScaled(70, 110, 50, 50, screen);
			SnowBlockUpMid.DrawScaled(120, 110, 50, 50, screen);
			SnowBlockUpFin.DrawScaled(170, 110, 50, 50, screen);

		}

		void display_woodsign(Surface* screen)
		{
			WoodSign.DrawScaled(0, 358, 90, 90, screen);
			screen->Print("Instructions", 6, 390, 0x492d00);
		}
	};
};//namespace Tmpl8


/* check if the flake has reached the bottom of the screen
if (flakesY[i] > ScreenHeight)
{
	flakesX[i] = Rand(ScreenWidth);
	flakesY[i] = 0;
	flakes_layer[i] = Rand(layer);
}*/