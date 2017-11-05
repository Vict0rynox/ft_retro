//
// Created by Victor Vasiliev on 11/5/17.
//

#include <ncurses.h>
#include "PlayerController.hpp"
#include "../model/Bullet.hpp"
#include "../event/MoveEvent.hpp"

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

Control::PlayerController::PlayerController(Model::Player *player,
											Utils::List<Event::IEvent *> *eventList,
											Utils::List<Model::Object *> *objectsList)
		: moveUpButtonKeyCode(KEY_UP),
		  moveDownButtonKeyCode(KEY_DOWN),
		  moveLeftButtonKeyCode(KEY_LEFT),
		  moveRightButtonKeyCode(KEY_RIGHT),
		  shootButtonKeyCode(32),
          player(player), eventList(eventList),  objectsList(objectsList)
{

}

Control::PlayerController::PlayerController(Model::Player *player,
											Utils::List<Event::IEvent *> *eventList,
											Utils::List<Model::Object *> *objectsList,
											int moveUpButtonKeyCode,
											int moveDownButtonKeyCode,
											int moveLeftButtonKeyCode,
											int moveRightButtonKeyCode,
											int shootButtonKeyCode)
		: moveUpButtonKeyCode(moveUpButtonKeyCode),
		  moveDownButtonKeyCode(moveDownButtonKeyCode),
		  moveLeftButtonKeyCode(moveLeftButtonKeyCode),
		  moveRightButtonKeyCode(moveRightButtonKeyCode),
		  shootButtonKeyCode(shootButtonKeyCode), player(player),
		  eventList(eventList), objectsList(objectsList)
{

}

bool Control::PlayerController::isHandle(int buttonCode)
{
	return (!player->isDestroy() && (buttonCode == moveUpButtonKeyCode ||
			buttonCode == moveDownButtonKeyCode ||
			buttonCode == moveLeftButtonKeyCode ||
			buttonCode == moveRightButtonKeyCode ||
			buttonCode == shootButtonKeyCode)
	);
}

void Control::PlayerController::handle(int buttonCode)
{
	if(!player->isDestroy()) {
		if (buttonCode == moveUpButtonKeyCode) {
			player->moveUp();
		} else if (buttonCode == moveDownButtonKeyCode) {
			player->moveDown();
		} else if (buttonCode == moveLeftButtonKeyCode) {
			player->moveLeft();
		} else if (buttonCode == moveRightButtonKeyCode) {
			player->moveRight();
		} else if (buttonCode == shootButtonKeyCode) {
			Model::Bullet *bullet = new Model::Bullet("bullet",
													  Model::Position(
															  player->getPosition().getX(),
															  player->getPosition().getY()-1),
													  -1, player->getDamage());
			objectsList->pushNode(bullet);
			eventList->pushNode(new Event::MoveEvent(bullet, bullet->getSpeed()));
		}
	}
}
