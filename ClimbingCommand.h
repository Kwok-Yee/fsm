#pragma once
#include "Command.h"
#include "Animation.h"

class ClimbingCommand : public Command
{
public:
	ClimbingCommand(Animation* a) { animation = a; };
	virtual void execute() { animation->climbing(); };
private:
	Animation * animation;
};