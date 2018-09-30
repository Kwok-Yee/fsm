#pragma once
#include "Command.h"
#include "Player.h"

class FireCommand : public Command
{
public:
	FireCommand(Player* p) { player = p; };
	virtual void execute() { player->fire(); };
	virtual void undo() { player->undoFire(); };
	virtual void redo() { player->printCommand(player->getPreviousCommand()); };
private:
	Player * player;
};