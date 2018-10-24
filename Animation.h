#pragma once

class Animation
{
	class State* current;
public:
	Animation();
	void setCurrent(State* s);
	int getAnimationState();
	void idle();
	void jumping();
	void climbing();
private:
	int animationState;
};