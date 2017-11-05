//
// Created by Victor Vasiliev on 11/5/17.
//

#include "Stars.hpp"

Model::Stars::Stars(): Model::Unit("Stars", Position(0,0), 1, 1),
						 view(new Utils::List<Model::Simbol>()), speed(1)
{
	view->pushNode(Simbol("|", Position(0, 0)));
	areaSize = Size(1, 1);
}

Model::Stars::Stars(std::string name, Model::Position position, int speed, int damage)
		: Model::Unit(name, position, 1, damage),
		  view(new Utils::List<Model::Simbol>()), speed(speed)
{
	view->pushNode(Simbol("|", Position(0, 0)));
	areaSize = Size(1, 1);
}

Model::Stars::~Stars()
{

}

Model::Stars::Stars(const Model::Stars &rhs)
		: Model::Unit(rhs.name, rhs.position, 1, rhs.damage),
		  areaSize(rhs.areaSize), view(rhs.view)
{

}

Model::Stars &Model::Stars::operator=(const Model::Stars &rhs)
{
	Model::Unit::operator=(rhs);
	view = rhs.view;
	areaSize = rhs.areaSize;
	return *this;
}

Utils::List<Model::Simbol> *Model::Stars::getView() const
{
	return view;
}

const Model::Size &Model::Stars::getAreaSize() const
{
	return areaSize;
}

int Model::Stars::getSpeed() const
{
	return speed;
}
