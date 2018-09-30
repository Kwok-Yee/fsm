#pragma once
#include "SDL.h"
#include "Command.h"

class InputHandler
{
public:
	void handleInput(SDL_Event &event);
	void setCommand(int num, Command* cmd);
private:
	Command* keyOne;
	Command* keyTwo;
	Command* keyThree;
	Command* keyFour;
	Command* keyFive;
	Command* undo;
	Command* redo;

	Command* prevCommand;
	Command* curCommand;
};