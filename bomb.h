#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
#include "dragon.h"
#include <cstdio> //printf
#include <SDL.h>
#include <string>
#include <cstdlib>


namespace Tmpl8 {
	//class Surface;
	static Sprite Bomb1(new Surface("bomb1.png"), 1); 

	//bomb animation sprites
	static Sprite BombA1(new Surface("deadDragon6.png"), 1);
	static Sprite BombA2(new Surface("deadDragon7.png"), 1);
	static Sprite BombA3(new Surface("deadDragon8.png"), 1);

	//static Sprite Bomba(new Surface("bombaanimata.png"), 4);

	int var3 = 1;
	int ExplodeSpeed = 10;
	bool finishFinalBombAnimation = false;
	 
	class Bomb {
	public:
		
		void throw_bomb(int Xdragon,int Ydragon, Surface* screen)
		{
			Bomb1.DrawScaled(Xdragon, Ydragon, 60, 60, screen);
		}
	
		void explode_bomb(int Xdragon, int Ydragon, Surface* screen)
		{
		if (var3 < ExplodeSpeed)
			{
				BombA1.DrawScaled(Xdragon, Ydragon, 60, 60, screen);
				var3++;
			}
			if (var3 >= ExplodeSpeed && var3 < ExplodeSpeed * 2)
			{
				BombA2.DrawScaled(Xdragon, Ydragon, 60, 60, screen);
				var3++;
			}
			if (var3 >= ExplodeSpeed * 2 && var3 < ExplodeSpeed * 3) 
			{
				BombA3.DrawScaled(Xdragon, Ydragon, 60, 60, screen);
				var3++;
			}
			if (var3 == ExplodeSpeed * 3)
			{
				finishFinalBombAnimation = true;
			}
		}
	};

};