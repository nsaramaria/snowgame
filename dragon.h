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
//using namespace Tmpl8::Character;
//using namespace Tmpl8::Character;


namespace Tmpl8{

	class Surface;
	//dragon flying from left to right animation
	static Sprite Dragon1(new Surface("dragon1.png"), 1);
	static Sprite Dragon2(new Surface("dragon2.png"), 1);
	static Sprite Dragon3(new Surface("dragon3.png"), 1);

	//dragon flying from right to left animation
	static Sprite DragonRev1(new Surface("dragonRev1.png"), 1);
	static Sprite DragonRev2(new Surface("dragonRev2.png"), 1);
	static Sprite DragonRev3(new Surface("dragonRev3.png"), 1);

	//dead dragon animation (if the dragon was flying from right to left)
	static Sprite DragonDead1(new Surface("deadDragon1.png"), 1);
	static Sprite DragonDead2(new Surface("deadDragon2.png"), 1);
	static Sprite DragonDead3(new Surface("deadDragon3.png"), 1);
	static Sprite DragonDead4(new Surface("deadDragon4.png"), 1);
	static Sprite DragonDead5(new Surface("bomb1.png"), 1);
	static Sprite DragonDead6(new Surface("deadDragon6.png"), 1);
	static Sprite DragonDead7(new Surface("deadDragon7.png"), 1);
	static Sprite DragonDead8(new Surface("deadDragon8.png"), 1);

	//dead dragon animation (if the dragon was flying from left to right)
	static Sprite DragonDeadRev1(new Surface("deadDragonRev1.png"), 1);
	static Sprite DragonDeadRev2(new Surface("deadDragonRev2.png"), 1);
	static Sprite DragonDeadRev3(new Surface("deadDragonRev3.png"), 1);
	static Sprite DragonDeadRev4(new Surface("deadDragonRev4.png"), 1);
	static Sprite DragonDeadRev5(new Surface("bombRev1.png"), 1);
	static Sprite DragonDeadRev6(new Surface("deadDragonRev6.png"), 1);
	static Sprite DragonDeadRev7(new Surface("deadDragonRev7.png"), 1);
	static Sprite DragonDeadRev8(new Surface("deadDragonRev8.png"), 1);

	int var = 1;
	int var2 = 1;
	//float previewDeltaTime = 0;
	int flyingSpeed = 24;
	int fallindspeed = 20;
	int Xdragon = 350;
	int Ydragon = 40;
	int initYBombPosition = 80;
	int currentYBombPosition = 0;
	int initXBombPosition = 350 ;
	bool leftToRight = true;
	bool isThrown = false;
	int bombCount = 0;
	//Dragon dragonBomb;
	//bool hit = false;
	bool alive = true;
	bool playDeadDragonAnimation = true;
	bool finishanimation = false;
	//Dragon dragon;

	class Dragon
	{
	public: 
		//Lives lives;
		Character ch;
		Bomb bomb;
		
		void animate_dragon(Surface* screen, float deltaTime)
		{
			if (alive)
			{

				if (var < flyingSpeed)
				{
					leftToRight ? Dragon1.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonRev1.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var++;
					leftToRight ? Xdragon++ : Xdragon--;
				}
				if (var >= flyingSpeed && var < flyingSpeed * 2)
				{
					leftToRight ? Dragon2.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonRev2.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var++;
					leftToRight ? Xdragon++ : Xdragon--;
				}
				if (var >= flyingSpeed * 2 && var < flyingSpeed * 3) {
					leftToRight ? Dragon3.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonRev3.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var++;
					leftToRight ? Xdragon++ : Xdragon--;
				}
				if (var >= flyingSpeed * 3 && var < flyingSpeed * 4)
				{
					leftToRight ? Dragon2.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonRev2.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var++;
					leftToRight ? Xdragon++ : Xdragon--;
				}
				if (var == flyingSpeed * 4) {
					var = 1;
				}
				if (Xdragon == ScreenWidth - 100 || Xdragon == 100) {
					leftToRight = !leftToRight;
				}
				if (Xdragon == initXBombPosition) {
					isThrown = true;
					currentYBombPosition = initYBombPosition;
				}
				if (currentYBombPosition > ScreenHeight - 120) {
					isThrown = false;
					currentYBombPosition = initYBombPosition;
					int randomN = int(Rand(600));
					initXBombPosition = randomN < 110 || randomN>600 ? 140 : randomN;
				}
				if (isThrown) {
					if (checkHitCharacterDrClass())
					{
						bomb.explode_bomb(initXBombPosition, currentYBombPosition, screen);
					}
					else
					{
						bomb.throw_bomb(initXBombPosition, currentYBombPosition, screen);
					}
					currentYBombPosition++;
					if (currentYBombPosition == initYBombPosition + 2) {
						bombCount++;
					}
				}
			}
		}
		
		bool checkHitCharacterDrClass() {
			if (getYBombPosition() > ch.getYCharactPosition() + 10
				&& getXBombPosition() > ch.getXCharactPosition() - 60 + 10
				&& getXBombPosition() < ch.getXCharactPosition() + 87 - 10)
			{
				//characterWasHit = true;
				return true;
			}
			else {
				return false;
			}

		}

		void dead_dragon_animation(Surface* screen)
		{
			alive = false;
			if (playDeadDragonAnimation)
			{
				if (var2 < fallindspeed)
				{
					leftToRight ? DragonDead1.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonDeadRev1.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var2++;
					leftToRight ? Xdragon++ : Xdragon--;
					Ydragon++;
				}
				if (var2 >= fallindspeed && var2 < fallindspeed * 2)
				{
					leftToRight ? DragonDead2.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonDeadRev2.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var2++;
					leftToRight ? Xdragon++ : Xdragon--;
					Ydragon++;
				}
				if (var2 >= fallindspeed * 2 && var2 < fallindspeed * 3) {
					leftToRight ? DragonDead3.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonDeadRev3.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var2++;
					leftToRight ? Xdragon++ : Xdragon--;
					Ydragon++;
				}
				if (var2 >= fallindspeed * 3 && var2 < fallindspeed * 4)
				{
					leftToRight ? DragonDead4.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonDeadRev4.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var2++;
					leftToRight ? Xdragon++ : Xdragon--;
					Ydragon++;
				}
				if (var2 >= fallindspeed * 4 && var2 < fallindspeed * 5)
				{
					leftToRight ? DragonDead5.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonDeadRev5.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var2++;
					leftToRight ? Xdragon++ : Xdragon--;
					Ydragon++;
				}
				if (var2 >= fallindspeed * 5 && var2 < fallindspeed * 6) {
					leftToRight ? DragonDead6.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonDeadRev6.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var2++;
					leftToRight ? Xdragon++ : Xdragon--;
					Ydragon++;
				}
				if (var2 >= fallindspeed * 6 && var2 < fallindspeed * 7)
				{
					leftToRight ? DragonDead7.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonDeadRev7.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var2++;
					leftToRight ? Xdragon++ : Xdragon--;
					Ydragon++;
				}
				if (var2 >= fallindspeed * 7 && var2 < fallindspeed * 8)
				{
					leftToRight ? DragonDead8.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonDeadRev8.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
					var2++;
					leftToRight ? Xdragon++ : Xdragon--;
					Ydragon++;
				}
				
				if (var2 == fallindspeed * 8) {
					playDeadDragonAnimation=false;
					finishanimation = true;
				}
			}
		}
	
		int getXdragonPosition()
		{
			return Xdragon;
		}
		int getYdragonPosition()
		{
			return Ydragon;
		}
		int getYBombPosition()
		{
			return currentYBombPosition;
		}

		int getXBombPosition()
		{
			return initXBombPosition;
		}
		bool isBombThrown() {
			return isThrown;
		}
		int getBombCount() {
			return bombCount;
		}

		
	}; //class Dragon

};