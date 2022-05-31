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

const int totalFlakes = 200;
const int layer = 3;
float flakesX[700];
float flakesY[700];
int flakesLayer[700];
int fColor;
float speed[700];
float fScreenWidth = 800.0f;
float fScreenHeight = 512.0f;

namespace Tmpl8 {
	//class Surface;
	static Sprite snowBlockInit(new Surface("1.png"), 1);
	static Sprite snowBlockMid(new Surface("2.png"), 1);
	static Sprite snowBlockFin(new Surface("3.png"), 1);

	static Sprite snowBlockUpInit(new Surface("14.png"), 1);
	static Sprite snowBlockUpMid(new Surface("15.png"), 1);
	static Sprite snowBlockUpFin(new Surface("16.png"), 1);

	static Sprite woodSign(new Surface("Sign_1.png"), 1);

	static Sprite chBar(new Surface("0_Citizen_Communication_000.png"), 1);
	static Sprite drBar(new Surface("dragon2.png"), 1);

	int xInstructions = 6;
	int yInstructions = 370;

	class Snow
	{
	public:
		void initializeFlakes()
		{
			for (int i = 0; i < totalFlakes; i++)
			{
				flakesX[i] = Rand(fScreenWidth);
				flakesY[i] = Rand(fScreenHeight);
				flakesLayer[i] = int(Rand(layer));
			}
		}
		void drawFlakes(Surface* screen, float deltaTime)
		{
			//making 3 different snowfleaks types with different form , color and speed
			for (int i = 0; i < totalFlakes; i++)
			{
				if (flakesLayer[i] == 0)
				{
					speed[i] = 0.1f * deltaTime;
					fColor = 0x4cbfe0;
					//circular snowfleaks
					screen->Plot(int(flakesX[i]), int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]) + 1, fColor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 1, fColor);
				}
				if (flakesLayer[i] == 1)
				{
					speed[i] = 0.2f * deltaTime;
					fColor = 0xcae9ff;
					//star snowfleaks
					screen->Plot(int(flakesX[i]), int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]) + 2, int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]) + 3, int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 1, fColor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 2, fColor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 3, fColor);
					screen->Plot(int(flakesX[i]) - 1, int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]) - 2, int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]) - 3, int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) - 1, fColor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) - 2, fColor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) - 3, fColor);
				}
				if (flakesLayer[i] == 2)
				{
					speed[i] = 0.3f * deltaTime;
					fColor = 0x8fcbff;
					//circular snowfleaks
					screen->Plot(int(flakesX[i]), int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]), fColor);
					screen->Plot(int(flakesX[i]) + 1, int(flakesY[i]) + 1, fColor);
					screen->Plot(int(flakesX[i]), int(flakesY[i]) + 1, fColor);
				}
			}
		}
		void movementFlakes()
		{
			for ( int i = 0; i < totalFlakes; i++)
			{
				flakesY[i] += speed[i];

				if (flakesY[i] > fScreenHeight)
				{
					flakesX[i] = Rand(fScreenWidth);
					flakesY[i] = 0.0f;
					flakesLayer[i] = int(Rand(layer));
				}
			}
		}
	};//class Snow

	class Display
	{
	public:

		void displayGround(Surface* screen)
		{
			//ground blocks placed on the buttom of the screen
			snowBlockInit.DrawScaled(3, 442, 70, 70, screen);
			int placing = 70;
			for (int i = 1; i <= 10; i++)
			{
				snowBlockMid.DrawScaled(placing, 442, 70, 70, screen);
				placing += 70;
			}
			snowBlockFin.DrawScaled(727, 442, 70, 70, screen);
			
			//ground blocks placed on the top of the screen
			snowBlockUpInit.DrawScaled(80, 130, 40, 40, screen);
			snowBlockUpMid.DrawScaled(120, 130, 40, 40, screen);
			snowBlockUpFin.DrawScaled(160, 130, 40, 40, screen);

			snowBlockUpInit.DrawScaled(670, 300, 40, 40, screen);
			snowBlockUpMid.DrawScaled(710, 300, 40, 40, screen);
			snowBlockUpFin.DrawScaled(750, 300, 40, 40, screen);
		}

		void displayWoodsign(Surface* screen)
		{
			woodSign.DrawScaled(0, 348, 100, 100, screen);
			screen->Print("Kill the dragon", xInstructions, yInstructions, 0x492d00);
			screen->Print("by hitting it", xInstructions, yInstructions+10, 0x492d00);
			screen->Print("six times and", xInstructions, yInstructions+20, 0x492d00);
			screen->Print("watch out for", xInstructions, yInstructions+30, 0x492d00);
			screen->Print("bombs", xInstructions, yInstructions+40, 0x492d00);
		}

		void displayChBar(Surface* screen)
		{
			chBar.DrawScaled(580, 1, 40, 40, screen);
		}

		void displayDrBar(Surface* screen)
		{
			drBar.DrawScaled(-5, -2, 57, 57, screen);
		}
	};
};//namespace Tmpl8
