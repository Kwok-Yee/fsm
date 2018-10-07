#pragma once
#include "Animation.h"
#include "State.h"

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a);
	void climbing(Animation* a);	
};