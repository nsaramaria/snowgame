#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf
#include <SDL.h>


namespace Tmpl8
{
	Sprite* entitySprite = new Sprite(new Surface("assets/bombExplosion.png"), 4);
	float entityFrame = 0.0f;

	class Entity
	{
	public:
		
		void Animation(float start, float finish, float animationSpeed, float deltaTime)
		{
			entityFrame += animationSpeed * deltaTime;
			if (entityFrame >= finish)  entityFrame = start; 
			entitySprite->SetFrame((int)floorf(entityFrame));

		}

		/*void Animation(float first, float last, float speed, float deltaTime)
		{
			entityFrame += speed * deltaTime;
			if (entityFrame >= last)  entityFrame = first;
			entitySprite->SetFrame(entityFrame);

		}*/
		int GetEntityFrame()
		{
			return entityFrame;
		}
	};
};