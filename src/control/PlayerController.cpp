//
// Created by Victor Vasiliev on 11/5/17.
//

#include <ncurses.h>
#include "PlayerController.hpp"

Control::PlayerController::PlayerController()
		: moveUpButtonKeyCode(KEY_UP),
		  moveDownButtonKeyCode(KEY_DOWN),
		  moveLeftButtonKeyCode(KEY_LEFT),
		  moveRightButtonKeyCode(KEY_RIGHT),
		  shootButtonKeyCode(32), player()
{

}

Control::PlayerController::PlayerController(
		const Control::PlayerController &rhs)
		: moveUpButtonKeyCode(rhs.moveUpButtonKeyCode),
		  moveDownButtonKeyCode(rhs.moveDownButtonKeyCode),
		  moveLeftButtonKeyCode(rhs.moveLeftButtonKeyCode),
		  moveRightButtonKeyCode(rhs.moveRightButtonKeyCode),
		  shootButtonKeyCode(rhs.shootButtonKeyCode), player(rhs.player)
{

}

Control::PlayerController &
Control::PlayerController::operator=(const Control::PlayerController &rhs)
{
	player = rhs.player;
	return *this;
}

Control::PlayerController::~PlayerController()
{

}

Control::PlayerController::PlayerController(Model::Player *player)
		: player(player), moveUpButtonKeyCode(KEY_UP),
		  moveDownButtonKeyCode(KEY_DOWN),
		  moveLeftButtonKeyCode(KEY_LEFT),
		  moveRightButtonKeyCode(KEY_RIGHT),
		  shootButtonKeyCode(32)
{

}

Control::PlayerController::PlayerController(Model::Player *player,
											int moveUpButtonKeyCode,
											int moveDownButtonKeyCode,
											int moveLeftButtonKeyCode,
											int moveRightButtonKeyCode,
											int shootButtonKeyCode)
		: moveUpButtonKeyCode(moveUpButtonKeyCode),
		  moveDownButtonKeyCode(moveDownButtonKeyCode),
		  moveLeftButtonKeyCode(moveLeftButtonKeyCode),
		  moveRightButtonKeyCode(moveRightButtonKeyCode),
		  shootButtonKeyCode(shootButtonKeyCode), player(player)
{

}

bool Control::PlayerController::isHandle(int buttonCode)
{
	return (buttonCode == moveUpButtonKeyCode ||
			buttonCode == moveDownButtonKeyCode ||
			buttonCode == moveLeftButtonKeyCode ||
			buttonCode == moveRightButtonKeyCode ||
			buttonCode == shootButtonKeyCode
	);
}

void Control::PlayerController::handle(int buttonCode)
{

	if (buttonCode == moveUpButtonKeyCode) {
		player->moveUp();
	} else if (buttonCode == moveDownButtonKeyCode) {
		player->moveDown();
	} else if (buttonCode == moveLeftButtonKeyCode) {
		player->moveLeft();
	} else if (buttonCode == moveRightButtonKeyCode) {
		player->moveRight();
	} else if (buttonCode == shootButtonKeyCode) {
		//TODO: shoot
	}
}
