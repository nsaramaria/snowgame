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
float speed[700];
float FScreenWidth = 800.0f;
float FScreenHeight = 512.0f;

namespace Tmpl8 {
	class Surface;
	static Sprite SnowBlockInit(new Surface("1.png"), 1);
	static Sprite SnowBlockMid(new Surface("2.png"), 1);
	static Sprite SnowBlockFin(new Surface("3.png"), 1);

	static Sprite SnowBlockUpInit(new Surface("14.png"), 1);
	static Sprite SnowBlockUpMid(new Surface("15.png"), 1);
	static Sprite SnowBlockUpFin(new Surface("16.png"), 1);

	static Sprite WoodSign(new Surface("Sign_1.png"), 1);

	static Sprite ChBar(new Surface("0_Citizen_Communication_000.png"), 1);
	static Sprite DrBar(new Surface("dragon2.png"), 1);

	class Snow
	{
	public:
		void initialize_flakes()
		{
			for (int i = 0; i < Total_flakes; i++)
			{
				flakesX[i] = Rand(FScreenWidth);
				flakesY[i] = Rand(FScreenHeight);
				flakes_layer[i] = int(Rand(layer));
			}
			//int a = 1;
		}
		void draw_flakes(Surface* screen, float deltaTime)
		{
			//making 3 different snowfleaks types with different form , color and speed
			//float test = flakesY[1];
			for (int i = 0; i < Total_flakes; i++)
			{
				if (flakes_layer[i] == 0)
				{
					speed[i] = 0.1f * deltaTime;
					fcolor = 0x4cbfe0;
					//circular snowfleaks
					screen->Plot(int(flakesX[i]), int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]) + 1, fcolor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 1, fcolor);
				}
				if (flakes_layer[i] == 1)
				{
					speed[i] = 0.2f * deltaTime;
					fcolor = 0xcae9ff;
					//star snowfleaks
					screen->Plot(int(flakesX[i]), int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]) + 2, int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]) + 3, int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 1, fcolor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 2, fcolor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 3, fcolor);
					screen->Plot(int(flakesX[i]) - 1, int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]) - 2, int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]) - 3, int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) - 1, fcolor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) - 2, fcolor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) - 3, fcolor);
				}
				if (flakes_layer[i] == 2)
				{
					speed[i] = 0.3f * deltaTime;
					fcolor = 0x8fcbff;
					//circular snowfleaks
					screen->Plot(int(flakesX[i]), int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]), fcolor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]) + 1, fcolor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 1, fcolor);
				}
			}

		}
		void movement_flakes()
		{
			for ( int i = 0; i < Total_flakes; i++)
			{
				flakesY[i] += speed[i];

				if (flakesY[i] > FScreenHeight)
				{
					flakesX[i] = Rand(FScreenWidth);
					flakesY[i] = 0.0f;
					flakes_layer[i] = int(Rand(layer));
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
			SnowBlockUpInit.DrawScaled(80, 130, 40, 40, screen);
			SnowBlockUpMid.DrawScaled(120, 130, 40, 40, screen);
			SnowBlockUpFin.DrawScaled(160, 130, 40, 40, screen);

			SnowBlockUpInit.DrawScaled(670, 300, 40, 40, screen);
			SnowBlockUpMid.DrawScaled(710, 300, 40, 40, screen);
			SnowBlockUpFin.DrawScaled(750, 300, 40, 40, screen);
		}

		void display_woodsign(Surface* screen)
		{
			WoodSign.DrawScaled(0, 348, 100, 100, screen);
			screen->Print("Kill the dragon", 6, 370, 0x492d00);
			screen->Print("by hitting it", 6, 380, 0x492d00);
			screen->Print("six times and", 6, 390, 0x492d00);
			screen->Print("watch out for", 6, 400, 0x492d00);
			screen->Print("bombs", 6, 410, 0x492d00);
		}

		void display_ch_bar(Surface* screen)
		{
			ChBar.DrawScaled(580, 1, 40, 40, screen);
		}

		void display_dr_bar(Surface* screen)
		{
			DrBar.DrawScaled(-5, -2, 57, 57, screen);
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