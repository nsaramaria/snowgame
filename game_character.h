#pragma once
#include <iostream>
#include "surface.h"
#include "game.h"
#include "template.h"
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

	static Sprite Dragon1(new Surface("dragon1.png"), 1);
	static Sprite Dragon2(new Surface("dragon2.png"), 1);
	static Sprite Dragon3(new Surface("dragon3.png"), 1);

    class Sprite;

	int x = 350;
	int y = 368;

	class Character
	{
	public:
		
		void Movement(Surface*screen)
		{

			if (GetAsyncKeyState(VK_LEFT))
			{
				//decrement x
				x -= 2;
				CharacterL.DrawScaled(x, y, 87, 87, screen);
			
			}
			else
			{
				if (GetAsyncKeyState(VK_RIGHT))
				{
					//increment x
					x += 2;
					CharacterR.DrawScaled(x, y, 87, 87, screen);
				}
				else
				{
					CharacterB.DrawScaled(x, y, 87, 87, screen);
				}
			}
		}
	};
};