#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
#include "dragon.h"
#include <cstdio> //printf
#include <SDL.h>
#include <string>
#include <cstdlib>
#include <ctime>

namespace Tmpl8 {
	int cLivesCount = 3;
	int dLivesCount = 6;
	bool hasLivesUpdated = false;
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
		void hitCharacter()
		{
			if (checkHitCharacter())
			{
				updateCLives();
			}
		}
		//creat a function that decreases life only by one per hit
		void updateCLives() {
			if (dragonBomb.getBombCount() > bombIndex)
			{
				cLivesCount--;//Character lives 
				//bombIndex variable restrict lives from decreasing more than once per hit
				bombIndex = dragonBomb.getBombCount();
			}
		}
		int cLivesNr()
		{
			return cLivesCount;
		}
		bool checkHitCharacter() { //check if the bomb hit the Character
			if (dragonBomb.getYBombPosition() > ch.getYCharactPosition() + 10
				&& dragonBomb.getXBombPosition() > ch.getXCharactPosition() - 50
				&& dragonBomb.getXBombPosition() < ch.getXCharactPosition() + 77)
			{
				return true;
			}
			else {
				return false;
			}
		}

		//create functions for character lives
		void hitDragon()
		{
			if (checkHitDragon())
			{
				updateDLives();

			}
		}
		void updateDLives() {
			if (snowball.getSnowballCount() > snowballIndex) {
				dLivesCount--;
				snowballIndex = snowball.getSnowballCount();
			}
		}
		int dLivesNr()
		{
			return dLivesCount;
		}
		bool checkHitDragon() {
			if (!ballIsThrown) {
				return false;
			}
			if ((snowball.getYPosition() < dragon.getYdragonPosition() + 87 - 30)
				&& (snowball.getXPosition() >= dragon.getXdragonPosition() - 50 + 30)
				&& (snowball.getXPosition() <= dragon.getXdragonPosition() + 87 - 35))
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
		void cHealthBarUpdate(Surface*screen,int cLivesCount)
		{
			colorRange[0] = 0;
			colorRange[1] = 0xe02e00;
			colorRange[2] = 0xff7702;
			colorRange[3] = 0x00ff00;
		
			screen->Bar(620, 10, 620 + cLivesCount * 55, 30, colorRange[cLivesCount]);

		}
		void dHealthBarUpdate(Surface* screen, int dLivesCount)
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