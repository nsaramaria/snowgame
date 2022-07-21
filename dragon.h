#pragma once
#include <iostream>
#include "surface.h"
#include "game.h"
#include "template.h"
#include "bomb.h"
#include "GameCharacter.h"
#include "Entity.h"
#include <SDL.h>
#include <cstdio> //printf
#include <string>
#include <Windows.h>
#include <thread>


namespace Tmpl8{

	Sprite* deadDragon = new Sprite(new Surface("assets/deadDragon.png"), 8);
	Sprite* lToRDragon = new Sprite(new Surface("assets/lToRDragon.png"), 9);
	Sprite* rToLDragon = new Sprite(new Surface("assets/rToLDragon.png"), 9);
	Sprite* bombExplosion = new Sprite(new Surface("assets/bombExplosion.png"), 4);

	int Xdragon = 350;
	int Ydragon = 50;
	int initYBombPosition = 80;
	int currentYBombPosition = 0;
	int initXBombPosition = 350 ;
	bool leftToRight = true;
	bool isThrown = false;
	int bombCount = 0;
	bool alive = true;
	bool finishanimation = false;

	class Dragon
	{
	public:
		Entity entity;
		Character ch;
		Bomb bomb;

		void AnimateDragon(Surface* screen, float deltaTime)
		{
			if (alive)
			{   //animate the dragon considering its direction
				if (leftToRight)
				{
					entitySprite = lToRDragon;
					Xdragon++;
				}
				else
				{
					entitySprite = rToLDragon;
					Xdragon--; 
				}
				entity.Animation(0.0f, 9.0f, 0.01f, deltaTime);
				entitySprite->Draw(screen, Xdragon, Ydragon);

				//switch direction when it reaches the edge of the flying area
				if (Xdragon == ScreenWidth - 100 || Xdragon == 100) {
					leftToRight = !leftToRight;
				}
				//throw the first bomb
				if (Xdragon == initXBombPosition) {
					isThrown = true;
					currentYBombPosition = initYBombPosition;
				}
				//the bomb disappear when it aproaches the ground 
				if (currentYBombPosition > ScreenHeight - 120) {
					isThrown = false;
					//reset the bomb coordinates and pick a random value for the X position
					currentYBombPosition = initYBombPosition;
					int randomN = int(Rand(600));
					initXBombPosition = randomN < 110 || randomN>600 ? 200 : randomN;
				}
				if (isThrown) {
					if (CheckHitCharacterDrClass())
					{   //animate the bomb if it hit the character
						entitySprite = bombExplosion;
						entity.Animation(0.0f, 4.0f, 0.01f, deltaTime);
						bombExplosion->Draw(screen, initXBombPosition, currentYBombPosition);
					}
					else
					{
						bomb.ThrowBomb(initXBombPosition, currentYBombPosition, screen);
					}
					currentYBombPosition++;
					if (currentYBombPosition == initYBombPosition + 2) {
						bombCount++;
					}
				}
			}
		}
        //check if the bomb hit the character
		bool CheckHitCharacterDrClass() {
			if (GetYBombPosition() > ch.GetYCharactPosition() + 10
				&& GetXBombPosition() > ch.GetXCharactPosition() - 60 + 10
				&& GetXBombPosition() < ch.GetXCharactPosition() + 87 - 10)
			{
				return true;
			}
			else {
				return false;
			}
		}
		void DeadDragonAnimation(Surface* screen, float deltaTime)
		{
			finishanimation = false;
			alive = false;
			entitySprite = deadDragon;
			entity.Animation(0.0f, 8.0f, 0.01f, deltaTime);
			entitySprite->Draw(screen, Xdragon, Ydragon);
			Xdragon++; Ydragon++;
			if (entity.GetEntityFrame() == 0.0000000000000000f)
			{
				finishanimation = true;
			}

		}
		int GetXdragonPosition()
		{
			return Xdragon;
		}
		int GetYdragonPosition()
		{
			return Ydragon;
		}
		int GetYBombPosition()
		{
			return currentYBombPosition;
		}
		int GetXBombPosition()
		{
			return initXBombPosition;
		}
		bool BombIsThrown() {
			return isThrown;
		}
		int GetBombCount() {
			return bombCount;
		}
	}; 
};