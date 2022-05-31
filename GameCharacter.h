#pragma once
#include <iostream>
#include "surface.h"
#include "game.h"
#include "template.h"
#include "snowball.h"
#include <SDL.h>
#include <cstdio> //printf
#include <string>
#include <Windows.h>
#include <vcruntime.h>


namespace Tmpl8 {
	//class Surface;  class Sprite;
	static Sprite characterB(new Surface("0_Citizen_Walk_000.png"), 1);//character from back
	static Sprite characterL(new Surface("0_Citizen_Walk_000S.png"), 1);//character from left side
	static Sprite characterR(new Surface("0_Citizen_Walk_000D.png"), 1);//character from right side

	int xCharacter = 350;
	int yCharacter = 368;
	int initYBallPosition = yCharacter - 60;
	int currentYBallPosition = initYBallPosition;
	bool ballIsThrown = false ; 
	//const int ballsMaxNumber = 2;
	//int countBalls=0;

	class Character
	{  
	public:
		Snowball snowball;
		
		void Movement(Surface*screen)
		{

			if (GetAsyncKeyState(VK_LEFT))
			{
				xCharacter -= 2;
				characterL.DrawScaled(xCharacter, yCharacter, 87, 87, screen);
			
			}
			else
			{
				if (GetAsyncKeyState(VK_RIGHT))
				{
					xCharacter += 2;
					characterR.DrawScaled(xCharacter, yCharacter, 87, 87, screen);
				}
				else
				{
					characterB.DrawScaled(xCharacter, yCharacter, 87, 87, screen);
				}
			}
			if(GetAsyncKeyState(VK_SPACE))
			{ 
				ballIsThrown = true;
			}
			
			if (ballIsThrown) 
			{
				snowball.throwBall(xCharacter, currentYBallPosition, screen);
			}
			 resetThrow();

		}
		//reset the position of the snowball
		void resetThrow() 
		{
			if (snowball.getYPosition()==21) {
				ballIsThrown = false;
			}
		}
		int getXCharactPosition()
		{
			return xCharacter;
		}
		int getYCharactPosition()
		{
			return yCharacter;
		}
	

	};//class Character
};