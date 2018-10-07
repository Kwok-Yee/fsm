#pragma once
#include "SDL.h"
#include "Animation.h"

class InputHandler
{
public:
	InputHandler();
	void handleInput(SDL_Event &event);
private:
	Animation* animation;
};