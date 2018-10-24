#pragma once
#include <iostream>

using namespace std;

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
protected:
	Command() {}
};