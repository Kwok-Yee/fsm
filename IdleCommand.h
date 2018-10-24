#pragma once
#include "Command.h"
#include "Animation.h"

class IdleCommand : public Command
{
public:
	IdleCommand(Animation* a) { animation = a; };
	virtual void execute() { animation->idle(); };
private:
	Animation * animation;
};