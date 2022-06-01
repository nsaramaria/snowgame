#pragma once
#include <iostream>
#include "surface.h"
#include "game.h"
#include "template.h"
#include "snowball.h"
#include <SDL.h>
#include <cstdio> //printf


namespace Tmpl8 {
	
	static Sprite characterB(new Surface("assets/citizenWalkB.png"), 1);//character from back
	static Sprite characterR(new Surface("assets/citizenWalkR.png"), 1);//character from right side
	static Sprite characterL(new Surface("assets/citizenWalkL.png"), 1);//character from left side

	int xCharacter = 350;
	int yCharacter = 368;
	int initYBallPosition = yCharacter - 60;
	int currentYBallPosition = initYBallPosition;
	bool ballIsThrown = false ; 

	class Character
	{  
	public:
		Snowball snowball;
		
		void Movement(Surface* screen)
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
			if (GetAsyncKeyState(VK_SPACE))
			{   //throw the ball when hit SPACE
				ballIsThrown = true;
			}
			if (ballIsThrown)
			{
				snowball.ThrowBall(xCharacter, currentYBallPosition, screen);
			}
			ResetThrow();
		}
		void ResetThrow() 
		{
			if (snowball.GetYPosition()==20) {
				ballIsThrown = false;
			}
		}
		int GetXCharactPosition()
		{
			return xCharacter;
		}
		int GetYCharactPosition()
		{
			return yCharacter;
		}
	};
};