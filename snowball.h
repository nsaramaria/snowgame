#pragma once
#include <iostream>
#include "surface.h"
#include "game.h"
#include "template.h"
#include "bomb.h"
#include "game_character.h"
#include <SDL.h>
#include <cstdio> //printf
#include <string>
#include <Windows.h>
#include <thread>

namespace Tmpl8 {
	class Surface;
    Sprite ball(new Surface("snowball.png"), 1);
	int YBall = 300;
	int XBall = -1;
	class Snowball {
		
	public:
		void throw_ball( int XCharacter,int YCharacter, Surface* screen)
		{
			if (XBall<0) {
				XBall = XCharacter;
			}
			if (YBall>20) {
				ball.DrawScaled(XBall, YBall, 50, 50, screen);
				YBall--;
			} else {
				YBall = 300;
				XBall = -1;
			}
		}

	
		int getXPosition() {
			return XBall;
		}
		int getYPosition() {
			return YBall;
		}
	};
}