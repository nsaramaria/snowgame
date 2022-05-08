#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
#include "backround.h"
//#include "dragon.h"
#include "bomb.h"
#include "game_character.h"
#include <cstdio> //printf
#include <SDL.h>
#include <string>
#include <cstdlib>
#include <ctime>

namespace Tmpl8 {
	int livesCount = 3;
	class Lives
	{
	public:
		Character ch;
		Dragon bombTh;
		void HitCharacter()
		{
			if (bombTh.getYBombPosition() > ch.getYCharactPosition() && bombTh.getXBombPosition() > ch.getXCharactPosition() - 10 && bombTh.getXBombPosition() < ch.getXCharactPosition() + 10)
			{
				livesCount--;
			}
			
		}

		int LivesNr()
		{
			return livesCount;
		}

	};

	class HealthBar
	{
	public:
		void healthBar_update(Surface*screen,int livesCount)
		{
			if (livesCount == 3)
			{
				screen->Bar(620, 10, 790, 30, 0x00ff00);
			}
			if (livesCount == 2)
			{
				screen->Bar(620, 10, 710, 30, 0xc67500);
			}
			if (livesCount == 1)
			{
				screen->Bar(620, 10, 650, 30, 0xe02e00);
			}
		}

	};

} ;  