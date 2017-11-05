//
// Created by Victor Vasiliev on 11/5/17.
//

#include "Bullet.hpp"

Model::Bullet::Bullet(): Model::Unit("Bullet", Position(0,0), 1, 1),
						 view(new Utils::List<Model::Simbol>()), speed(1)
{
	view->pushNode(Simbol("\xE2\x87\xAA\x0A", Position(0, 0)));
	areaSize = Size(1, 1);
}

Model::Bullet::Bullet(std::string name, Model::Position position, int speed, int damage)
		: Model::Unit(name, position, 1, damage),
		  view(new Utils::List<Model::Simbol>()), speed(speed)
{
	view->pushNode(Simbol("\xE2\x87\xAA\x0A", Position(0, 0)));
	areaSize = Size(1, 1);
}

Model::Bullet::~Bullet()
{

}

Model::Bullet::Bullet(const Model::Bullet &rhs)
		: Model::Unit(rhs.name, rhs.position, 1, rhs.damage),
		  view(rhs.view), areaSize(rhs.areaSize)
{

}

Model::Bullet &Model::Bullet::operator=(const Model::Bullet &rhs)
{
	Model::Unit::operator=(rhs);
	view = rhs.view;
	areaSize = rhs.areaSize;
	return *this;
}

Utils::List<Model::Simbol> *Model::Bullet::getView() const
{
	return view;
}

const Model::Size &Model::Bullet::getAreaSize() const
{
	return areaSize;
}

int Model::Bullet::getSpeed() const
{
	return speed;
}
