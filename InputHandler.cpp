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
		curCommand = keyOne;
		keyOne->execute();
		break;
	case SDLK_2:
		curCommand = keyTwo;
		keyTwo->execute();
		break;
	case SDLK_3:
		curCommand = keyThree;
		keyThree->execute();
		break;
	}
}

void InputHandler::bindKeysToCommands(int num, Command * cmd)
{
	curCommand = cmd;
	switch (num)
	{
	case 1:
		keyOne = curCommand;
		break;
	case 2:
		keyTwo = curCommand;
		break;
	case 3:
		keyThree = curCommand;
		break;
	}
}