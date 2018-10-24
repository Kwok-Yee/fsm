#include "Idle.h"
#include "Jumping.h"
#include "Climbing.h"

void Idle::jumping(Animation* a)
{
	cout << "Jumping" << endl;
	a->setCurrent(new Jumping());
	delete this;
};

void Idle::climbing(Animation* a)
{
	cout << "Climbing" << endl;
	a->setCurrent(new Climbing());
	delete this;
}