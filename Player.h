#pragma once
#include "Animation.h"
#include "Idle.h"
#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player(string n)
	{
		name = n;
		animation.setCurrent(new Idle());
	};


private:
	Animation animation;
	string name;
};