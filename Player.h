#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player(string n) { name = n; };

	void jump() { 
		printCommand(name + " jumps!");
		setPreviousCommand();
	};
	void undoJump() { 
		printCommand(name + " stops jump.");
		setPreviousCommand();
	};

	void fire() {
		printCommand(name + " fires!");
		setPreviousCommand();
	};
	void undoFire() {
		printCommand(name + " stops firing");
		setPreviousCommand();
	};

	void crouch() {
		printCommand(name + " crouches!");
		setPreviousCommand();
	};
	void undoCrouch() {
		printCommand(name + " stops crouching");
		setPreviousCommand();
	};

	void shield() {
		printCommand(name + " uses shield!");
		setPreviousCommand();
	};
	void undoShield() {
		printCommand(name + " stops shield");
		setPreviousCommand();
	};

	void melee() {
		printCommand(name + " uses melee!");
		setPreviousCommand();
	};
	void undoMelee() {
		printCommand(name + " stops melee");
		setPreviousCommand();
	};

	void printCommand(string msg) { currentCommand = msg; cout << currentCommand << endl; };
	void setPreviousCommand() { previousCommand = currentCommand; };
	string getPreviousCommand() { return previousCommand; };
private:
	string name;
	string currentCommand;
	string previousCommand;
};