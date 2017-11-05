//
// Created by Victor Vasiliev on 11/5/17.
//

#include "Enemies.hpp"

Model::Enemies::Enemies(): Model::Unit("Enemies", Position(0,0), 1, 1),
					   view(new Utils::List<Model::Simbol>()), speed(1)
{
	view->pushNode(Simbol("&", Position(0, 0)));
	areaSize = Size(1, 1);
}

Model::Enemies::Enemies(std::string name, Model::Position position, int speed, int damage)
		: Model::Unit(name, position, 1, damage),
		  view(new Utils::List<Model::Simbol>()), speed(speed)
{
	view->pushNode(Simbol("&", Position(0, 0)));
	areaSize = Size(1, 1);
}

Model::Enemies::~Enemies()
{

}

Model::Enemies::Enemies(const Model::Enemies &rhs)
		: Model::Unit(rhs.name, rhs.position, 1, rhs.damage),
		  areaSize(rhs.areaSize), view(rhs.view)
{

}

Model::Enemies &Model::Enemies::operator=(const Model::Enemies &rhs)
{
	Model::Unit::operator=(rhs);
	view = rhs.view;
	areaSize = rhs.areaSize;
	return *this;
}

Utils::List<Model::Simbol> *Model::Enemies::getView() const
{
	return view;
}

const Model::Size &Model::Enemies::getAreaSize() const
{
	return areaSize;
}

int Model::Enemies::getSpeed() const
{
	return speed;
}
