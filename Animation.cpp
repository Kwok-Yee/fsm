#include "Animation.h"
#include "Idle.h"

Animation::Animation()
{
	current = new Idle();
	animationState = 0;
}

void Animation::setCurrent(State* s)
{
	 current = s;
}

void Animation::idle()
{
	current->idle(this);
	animationState = 0;
}

void Animation::jumping()
{
	current->jumping(this);
	animationState = 1;
}

void Animation::climbing()
{
	current->climbing(this);
	animationState = 2;
}

int Animation::getAnimationState()
{
	return animationState;
}