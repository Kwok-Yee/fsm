#pragma once
#include "SDL.h"
#include "Command.h"
#include "Animation.h"

class InputHandler
{
public:
	InputHandler();
	void handleInput(SDL_Event &event);
	void bindKeysToCommands(int num, Command* cmd);
private:
	Command* keyOne;
	Command* keyTwo;
	Command* keyThree;
	Command* undo;
	Command* redo;

	Command* prevCommand;
	Command* curCommand;

	Animation* animation;
};