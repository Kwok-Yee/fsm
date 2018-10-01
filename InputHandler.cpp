#include "InputHandler.h"

void InputHandler::handleInput(SDL_Event &event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_1:
		curCommand = keyOne;
		keyOne->execute();
		//keyOne->undo();
		break;
	case SDLK_2:
		curCommand = keyTwo;
		keyTwo->execute();
		//keyTwo->undo();
		break;
	case SDLK_3:
		curCommand = keyThree;
		keyThree->execute();
		//keyThree->undo();
		break;
	case SDLK_4:
		curCommand = keyFour;
		keyFour->execute();
		//keyFour->undo();
		break;
	case SDLK_5:
		curCommand = keyFive;
		keyFive->execute();
		//keyFive->undo();
		break;
	case SDLK_6:
		prevCommand = curCommand;
		undo = prevCommand;
		undo->undo();
		break;
	case SDLK_7:
		prevCommand = curCommand;
		redo = prevCommand;
		redo->redo();
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
	case 4:
		keyFour = curCommand;
		break;
	case 5:
		keyFive = curCommand;
		break;
	}
}