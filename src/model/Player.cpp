//
// Created by Victor Vasiliev on 11/4/17.
//

#include "Player.hpp"

Utils::List<Model::Simbol>* Model::Player::getView() const
{
	return view;
}

Model::Player::Player()
		: Model::Unit("Player", Position(0, 0), 100, 10), view(new Utils::List<Model::Simbol>())
{
	view->pushNode(Simbol("\xf0\x90\x8D\x88", Position(0,0)));
	areaSize = Size(1,1);
}

Model::Player::Player(std::string name, Model::Position position)
		: Model::Unit(name, position, 100, 10), view(new Utils::List<Model::Simbol>())
{
	view->pushNode(Simbol("\xf0\x90\x8D\x88", Position(0,0)));
	areaSize = Size(1,1);
}

Model::Player::~Player()
{
	//TODO destroy View List
}

Model::Player::Player(const Model::Player &rhs) : Model::Unit(rhs)
{
	//TODO:: add view and areaSize
}

Model::Player &Model::Player::operator=(const Model::Player &rhs)
{
	//TODO:: add view and areaSize
	return dynamic_cast<Player &>(Model::Unit::operator=(rhs));
}

const Model::Size &Model::Player::getAreaSize() const
{
	return areaSize;
}


