#pragma once
#include <iostream>
#include "surface.h"
#include "game.h"
#include "template.h"
#include <SDL.h>
#include <cstdio> //printf
#include <string>
#include <Windows.h>

using namespace Tmpl8 {
	class Surface;
	class Assets
	{
	public:
		SDL_Window* gWindow = NULL;
		SDL_Surface* gScreenSurface = NULL;

	};

};