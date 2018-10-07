#include "Jumping.h"
#include "Idle.h"
#include "Climbing.h"

void Jumping::idle(Animation* a)
{
	cout << "Jumping -> Idle" << endl;
	a->setCurrent(new Idle());
	delete this;
};

void Jumping::climbing(Animation* a)
{
	cout << "Jumping -> Climbing" << endl;
	a->setCurrent(new Climbing());
	delete this;
}