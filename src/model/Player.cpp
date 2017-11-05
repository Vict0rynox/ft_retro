//
// Created by Victor Vasiliev on 11/4/17.
//

#include "Player.hpp"

Utils::List<Model::Simbol> *Model::Player::getView() const
{
	return view;
}

Model::Player::Player()
		: Model::Unit("Player", Position(0, 0), 100, 10),
		  view(new Utils::List<Model::Simbol>()), moveUDSpeed(1), moveLRSpeed(2)
{
	view->pushNode(Simbol("\xf0\x90\x8D\x88", Position(0, 0)));
	areaSize = Size(1, 1);
}

Model::Player::Player(std::string name, Model::Position position)
		:   Model::Unit(name, position, 100, 10),
		  view(new Utils::List<Model::Simbol>()), moveUDSpeed(1), moveLRSpeed(2)
{
	view->pushNode(Simbol("\xf0\x90\x8D\x88", Position(0, 0)));
	areaSize = Size(1, 1);
}

Model::Player::~Player()
{
	//TODO destroy View List
}

Model::Player::Player(const Model::Player &rhs)
		: Model::Unit(rhs), view(new Utils::List<Model::Simbol>())
{
	moveLRSpeed = rhs.moveLRSpeed;
	moveUDSpeed = rhs.moveUDSpeed;
}

Model::Player &Model::Player::operator=(const Model::Player &rhs)
{
	Model::Unit::operator=(rhs);
	moveLRSpeed = rhs.moveLRSpeed;
	moveUDSpeed = rhs.moveUDSpeed;
	return *this;
}

const Model::Size &Model::Player::getAreaSize() const
{
	return areaSize;
}

void Model::Player::moveUp()
{
	position.setY(position.getY() - moveUDSpeed);
}

void Model::Player::moveDown()
{
	position.setY(position.getY() + moveUDSpeed);
}

void Model::Player::moveLeft()
{
	position.setX(position.getX() - moveLRSpeed);

}

void Model::Player::moveRight()
{
	position.setX(position.getX() + moveLRSpeed);
}


