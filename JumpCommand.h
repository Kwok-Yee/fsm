#pragma once
#include "Command.h"
#include "Player.h"

class JumpCommand : public Command
{
public:
	JumpCommand(Player* p) { player = p; };
	virtual void execute() { player->jump(); };
	virtual void undo() { player->undoJump(); };
	virtual void redo() { player->printCommand(player->getPreviousCommand()); };
private:
	Player * player;
};