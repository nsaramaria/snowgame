#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf
#include <SDL.h>
#include <string>
#include <cstdlib>
#include <ctime>

namespace Tmpl8
{
	class Entity
	{
	public:
		Sprite* entitySprite = new Sprite(new Surface("assets/cube1.png"), 1);
		float entityFrame = 0.0f;
		void animateThis(float start, float finish, float animationSpeed, float deltaTime)
		{
			entityFrame += animationSpeed * deltaTime;
			if (entityFrame >= finish)entityFrame = start;
			entitySprite->SetFrame((int)floorf(entityFrame));
		}

		

	};

};