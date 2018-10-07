#include "InputHandler.h"
#include "Idle.h"
#include "Jumping.h"
#include "Climbing.h"

InputHandler::InputHandler()
{
	animation = new Animation();
}

void InputHandler::handleInput(SDL_Event &event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_1:
		animation->idle();
		break;
	case SDLK_2:
		animation->jumping();
		break;
	case SDLK_3:
		animation->climbing();
		break;
	}
}