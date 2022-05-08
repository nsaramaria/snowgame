#pragma once
#include <iostream>
#include "surface.h"
#include "game.h"
#include "template.h"
#include "bomb.h"
#include <SDL.h>
#include <cstdio> //printf
#include <string>
#include <Windows.h>
#include <thread>


namespace Tmpl8{

	class Surface;
	static Sprite Dragon1(new Surface("dragon1.png"), 1);
	static Sprite Dragon2(new Surface("dragon2.png"), 1);
	static Sprite Dragon3(new Surface("dragon3.png"), 1);

	static Sprite DragonRev1(new Surface("dragonRev1.png"), 1);
	static Sprite DragonRev2(new Surface("dragonRev2.png"), 1);
	static Sprite DragonRev3(new Surface("dragonRev3.png"), 1);

	int var = 1;
	//float previewDeltaTime = 0;
	int flyingSpeed = 24;
	int Xdragon = 350;
	int Ydragon = 40;
	int initYBombPosition = 80;
	int currentYBombPosition = 0;
	int initXBombPosition = 350 ;
	bool leftToRight = true;
	bool isThrown = false;


	class Dragon
	{
	public: 
		Bomb bomb;
		void animate_dragon(Surface* screen, float deltaTime)
		{
			
			if (var < flyingSpeed)
			{
				leftToRight ? Dragon1.DrawScaled(Xdragon, Ydragon, 87, 87, screen) : DragonRev1.DrawScaled(Xdragon, Ydragon, 87, 87, screen);
				var++;
				leftToRight ? Xdragon++ : Xdragon--;
			}
			if (var >= flyingSpeed && var < flyingSpeed*2)
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
				var=1;
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
				bomb.throw_bomb(initXBombPosition, currentYBombPosition, screen);
				currentYBombPosition++;
			}

		}
		int getYBombPosition()
		{
			return currentYBombPosition;
		}

		int getXBombPosition()
		{
			return initXBombPosition;
		}

		
	}; //class Dragon

};