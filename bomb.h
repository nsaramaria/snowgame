#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf
#include <SDL.h>


namespace Tmpl8 {

	static Sprite Bomb1(new Surface("assets/bomb1.png"), 1); 
	 
	class Bomb {
	public:

		void ThrowBomb(int Xbomb, int Ybomb, Surface* screen)
		{
			Bomb1.DrawScaled(Xbomb, Ybomb, 60, 60, screen);
		}

	};

};