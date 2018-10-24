#pragma once
#include "Command.h"
#include "Animation.h"

class JumpingCommand : public Command
{
public:
	JumpingCommand(Animation* a) { animation = a; };
	virtual void execute() { animation->jumping(); };
private:
	Animation * animation;
};