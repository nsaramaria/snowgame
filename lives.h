#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
#include "dragon.h"
#include <cstdio> //printf
#include <SDL.h>

namespace Tmpl8 {

	int cLivesCount = 3;
	int dLivesCount = 6;
	int bombIndex = -1;
	int snowballIndex = -1;
    int colorRange[6];
	 
	class Lives
	{
	public:
		Snowball snowball;
		Dragon dragon;
		Character ch;
		Dragon dragonBomb;

		//verify if the Character was hit by the bomb and update his lives if so
		void HitCharacter()
		{
			if (CheckHitCharacter())
			{
				UpdateCLives();
			}
		}
		//creat a function that decreases life only by one per hit
		void UpdateCLives() {
			if (dragonBomb.GetBombCount() > bombIndex)
			{
				cLivesCount--;//Character lives 
				//bombIndex variable restrict lives from decreasing more than once per hit
				bombIndex = dragonBomb.GetBombCount();
			}
		}
		int CLivesNo()
		{
			return cLivesCount;
		}
		bool CheckHitCharacter() { //check if the bomb hit the Character
			if (dragonBomb.GetYBombPosition() > ch.GetYCharactPosition() + 10
				&& dragonBomb.GetXBombPosition() > ch.GetXCharactPosition() - 50
				&& dragonBomb.GetXBombPosition() < ch.GetXCharactPosition() + 77)
			{
				return true;
			}
			else {
				return false;
			}
		}

		//create functions for character lives
		void HitDragon()
		{
			if (CheckHitDragon())
			{
				UpdateDLives();

			}
		}
		void UpdateDLives() {
			if (snowball.GetSnowballCount() > snowballIndex) {
				dLivesCount--;
				snowballIndex = snowball.GetSnowballCount();
			}
		}
		int DLivesNo()
		{
			return dLivesCount;
		}
		bool CheckHitDragon() {
			if (!ballIsThrown) {
				return false;
			}
			if ((snowball.GetYPosition() < dragon.GetYdragonPosition() + 87 - 40)
				&& (snowball.GetXPosition() >= dragon.GetXdragonPosition() - 50 + 40)
				&& (snowball.GetXPosition() <= dragon.GetXdragonPosition() + 87 - 40))
			{

				return true;
			}
			else {
				return false;
			}
		}
	};

	class HealthBar
	{
		//   functions that update the dragon and character health bar 
	    //   depending on their lives number
	public:
		void CHealthBarUpdate(Surface*screen,int cLivesCount)
		{
			colorRange[0] = 0;
			colorRange[1] = 0xe02e00;
			colorRange[2] = 0xff7702;
			colorRange[3] = 0x00ff00;
		
			screen->Bar(620, 10, 620 + cLivesCount * 55, 30, colorRange[cLivesCount]);
		}
		void DHealthBarUpdate(Surface* screen, int dLivesCount)
		{
			colorRange[0] = 0;
			colorRange[1] = 0xff0b1a;
			colorRange[2] = 0xe60657;
			colorRange[3] = 0xb60060;
			colorRange[4] = 0x8b006a;
			colorRange[5] = 0x48006a;
			colorRange[6] = 0x00006a;

			screen->Bar(40, 10, 65+ dLivesCount*20, 30, colorRange[dLivesCount]);
		}
	};
} ;  