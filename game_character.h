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
	class Surface;
	static Sprite CharacterB(new Surface("0_Citizen_Walk_000.png"), 1);//character from back
	static Sprite CharacterL(new Surface("0_Citizen_Walk_000S.png"), 1);//character from left side
	static Sprite CharacterR(new Surface("0_Citizen_Walk_000D.png"), 1);//character from right side


    class Sprite;

	int XCharacter = 350;
	int YCharacter = 368;
	int initYBallPosition = YCharacter - 60;
	int currentYBallPosition = initYBallPosition;
	bool ballIsThrown = false ; 
	const int ballsMaxNumber = 2;
	int countBalls=0;
	class Character
	{  
	public:
		Snowball snowball;
		
		void Movement(Surface*screen)
		{

			if (GetAsyncKeyState(VK_LEFT))
			{
				//decrement x
				XCharacter -= 2;
				CharacterL.DrawScaled(XCharacter, YCharacter, 87, 87, screen);
			
			}
			else
			{
				if (GetAsyncKeyState(VK_RIGHT))
				{
					//increment x
					XCharacter += 2;
					CharacterR.DrawScaled(XCharacter, YCharacter, 87, 87, screen);
				}
				else
				{
					CharacterB.DrawScaled(XCharacter, YCharacter, 87, 87, screen);
				}
			}
			if(GetAsyncKeyState(VK_SPACE))
			{ 
				ballIsThrown = true;
			}
			

			if (ballIsThrown) 
			{
				snowball.throw_ball(XCharacter, currentYBallPosition, screen);
			}
			 resetThrow();

		}
		void resetThrow() 
		{
			if (snowball.getYPosition()==21) {
				ballIsThrown = false;
			}
		}
		int getXCharactPosition()
		{
			return XCharacter;
		}
		int getYCharactPosition()
		{
			return YCharacter;
		}

	};//class Character
};