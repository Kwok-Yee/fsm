#pragma once
#include "Command.h"
#include "Player.h"

class CrouchCommand : public Command
{
public:
	CrouchCommand(Player* p) { player = p; };
	virtual void execute() { player->crouch(); };
	virtual void undo() { player->undoCrouch(); };
	virtual void redo() { player->printCommand(player->getPreviousCommand()); };
private:
	Player * player;
};