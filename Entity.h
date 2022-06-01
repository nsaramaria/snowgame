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
		int GetEntityFrame()
		{
			return entityFrame;
		}
	};
};