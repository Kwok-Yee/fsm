#include "Climbing.h"
#include "Idle.h"
#include "Jumping.h"

void Climbing::idle(Animation* a)
{
	cout << "Idle" << endl;
	a->setCurrent(new Idle());
	delete this;
};

void Climbing::jumping(Animation* a)
{
	cout << "Jumping" << endl;
	a->setCurrent(new Jumping());
	delete this;
}