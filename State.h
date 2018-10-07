#pragma once
#include "Animation.h"
#include <iostream>

using namespace std;

class State
{
public:
	virtual void idle(Animation* a)
	{
		cout << "Idle" << endl;
	}

	virtual void jumping(Animation* a)
	{
		cout << "Jumping" << endl;
	}

	virtual void climbing(Animation* a)
	{
		cout << "Climbing" << endl;
	}
};