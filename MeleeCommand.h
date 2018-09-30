#pragma once
#include "Command.h"
#include "Player.h"

class MeleeCommand : public Command
{
public:
	MeleeCommand(Player* p) { player = p; };
	virtual void execute() { player->melee(); };
	virtual void undo() { player->undoMelee(); };
	virtual void redo() { player->printCommand(player->getPreviousCommand()); };
private:
	Player * player;
};