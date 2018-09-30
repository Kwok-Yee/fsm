#pragma once
#include "Command.h"
#include "Player.h"

class ShieldCommand : public Command
{
public:
	ShieldCommand(Player* p) { player = p; };
	virtual void execute() { player->shield(); };
	virtual void undo() { player->undoShield(); };
	virtual void redo() { player->printCommand(player->getPreviousCommand()); };
private:
	Player * player;
};