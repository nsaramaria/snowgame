#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
//#include "game_character.h"
#include "dragon.h"
#include <cstdio> //printf
#include <SDL.h>
#include <string>
#include <cstdlib>
#include <ctime>

namespace Tmpl8 {
	int ClivesCount = 3;
	int DlivesCount = 6;
	bool hasLivesUpdated = false;
	int bombIndex = -1;
	int snowballIndex = -1;
    static bool characterWasHit = false;

	class Lives
	{
	public:
		//create functions for character lives
		Character ch;
		Dragon dragonBomb;
		Dragon dragon;
		Snowball snowball;

		void HitCharacter()
		{
			if (checkHitCharacter())
			{ 
				//characterWasHit = true;
				updateCLives();
			}
			
		}

		void updateCLives() {
			if (dragonBomb.getBombCount()> bombIndex) {
				ClivesCount--;
				bombIndex = dragonBomb.getBombCount();
				//characterWasHit = false;
			}
		}

		int CLivesNr()
		{
			return ClivesCount;
		}

		bool checkHitCharacter() {
			if (dragonBomb.getYBombPosition() > ch.getYCharactPosition() +10
				&& dragonBomb.getXBombPosition() > ch.getXCharactPosition() - 60+10
				&& dragonBomb.getXBombPosition() < ch.getXCharactPosition() + 87-10)
			{
				characterWasHit = true;
				return true;
			}
			else {
				return false;
			}
			
		}

		//create functions for character lives
		void HitDragon()
		{
			if (checkHitDragon())
			{
				updateDLives();

			}
		}
		void updateDLives() {
			if (snowball.getSnowballCount() > snowballIndex) {
				DlivesCount--;
				snowballIndex = snowball.getSnowballCount();
			}
		}
		int DLivesNr()
		{
			return DlivesCount;
		}
		bool checkHitDragon() {
			if (!ballIsThrown) {
				return false;
			}
			if ( (snowball.getYPosition()< dragon.getYdragonPosition() +87 -30)
				&& (snowball.getXPosition() >= dragon.getXdragonPosition() - 50 + 30 )
				&& (snowball.getXPosition() <= dragon.getXdragonPosition() + 87 - 35))
			{
				int x = snowball.getXPosition();
				int y = snowball.getYPosition();
				int xd = dragon.getXdragonPosition();
				int yd = dragon.getYdragonPosition();
				return true;
			}
			else {
				return false;
			}

		}


	};

	class HealthBar
	{
	public:
		void ChealthBar_update(Surface*screen,int ClivesCount)
		{
			if (ClivesCount == 3)
			{
				screen->Bar(620, 10, 790, 30, 0x00ff00);
			}
			if (ClivesCount == 2)
			{
				screen->Bar(620, 10, 710, 30, 0xff7702);
			}
			if (ClivesCount <= 1)
			{
				screen->Bar(620, 10, 650, 30, 0xe02e00);
			}
		}
		void DhealthBar_update(Surface* screen, int DlivesCount)
		{
			if (DlivesCount == 6)
			{
				screen->Bar(40, 10, 180, 30, 0x00006a); //  790-620=170
			}
			if (DlivesCount == 5)
			{
				screen->Bar(40, 10, 157, 30, 0x48006a);
			}
			if (DlivesCount == 4)
			{
				screen->Bar(40, 10, 134, 30, 0x8b006a);
			}
			if (DlivesCount == 3)
			{
				screen->Bar(40, 10, 111, 30, 0xb60060);
			}
			if (DlivesCount == 2)
			{
				screen->Bar(40, 10, 88, 30, 0xe60657);
			}
			if (DlivesCount <= 1)
			{
				screen->Bar(40, 10, 65, 30, 0xff0b1a);
			}
		}
	};

} ;  