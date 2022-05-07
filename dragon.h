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

namespace Tmpl8{

	static Sprite Dragon1(new Surface("dragon1.png"), 1);
	static Sprite Dragon1(new Surface("dragon2.png"), 1);
	static Sprite Dragon1(new Surface("dragon3.png"), 1);

	class Surface;
	/*class Dragon
	{
		int Xposition;
		int i;
		int Const = 1;
		int layer = Rand(3);

		void animation(Surface* screen)
		{
			for (Xposition = 200; Xposition <= 400; Xposition += Const)
			{
				if (Xposition == 400)
				{
					Const = Const * (-1);
				}

				if (Const == 1)
				{
					Dragon1.DrawScaled(Xposition, 110, 87, 87, screen);
				}
				if (Const == -1)
				{
					Dragon1.DrawScaled(Xposition, 110, 87, 87, screen);
				}
			}
		}
		
	};*/ //class Dragon

};