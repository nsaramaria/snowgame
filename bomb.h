#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
#include "dragon.h"
//#include "lives.h"
//#include "game_character.h"
#include <cstdio> //printf
#include <SDL.h>
#include <string>
#include <cstdlib>
//#include <ctime>
namespace Tmpl8 {
	class Surface;
	//Lives lives;
	static Sprite Bomb1(new Surface("bomb1.png"), 1); 
	//int bombXPosition;
	//int bombYPosition;
	class Bomb {
	public:
		
		void throw_bomb(int Xdragon,int Ydragon, Surface* screen)
		{
			Bomb1.DrawScaled(Xdragon, Ydragon, 60, 60, screen);
			Ydragon++;
			//bombXPosition = Xdragon;
			//bombYPosition = Ydragon;
		}

		
		//lives.HitCharacter(Xdragon, currentYBombPosition);
	};

};