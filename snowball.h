#pragma once
#include <iostream>
#include "surface.h"
#include "game.h"
#include "template.h"
#include "GameCharacter.h"
#include <SDL.h>
#include <cstdio> //printf
#include <string>
#include <Windows.h>
#include <thread>

namespace Tmpl8 {
	//class Surface;
    Sprite ball(new Surface("snowball.png"), 1);
	int yBall = 300;
	int xBall = -1;
	int SnowballCount = -1;

	class Snowball {
		
	public:
		void throwBall( int XCharacter,int YCharacter, Surface* screen)
		{
			if (xBall<0) {
				int save = XCharacter;
				xBall = save;
			}
			if (yBall>20) 
			{
				ball.DrawScaled(xBall, yBall, 50, 50, screen);
				yBall--;
				if (yBall == 200)
				{
					SnowballCount++;
				}
			}
			else //reset the coordinates when the snowball approaches the top
			{   yBall = 300;
			 //initialize xBall with a negative value so it gets the x position of the character in the first IF condition
 				xBall = -1; 
			}
		}

	
		int getXPosition() {
			return xBall;
		}
		int getYPosition() {
			return yBall;
		}
		int getSnowballCount()
		{
			return SnowballCount;
		}
	};
}