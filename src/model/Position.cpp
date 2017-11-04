//
// Created by Victor Vasiliev on 11/4/17.
//

#include "Position.hpp"

int Model::Position::getX() const
{
	return x;
}

void Model::Position::setX(int x)
{
	this->x = x;
}

int Model::Position::getY() const
{
	return y;
}

void Model::Position::setY(int y)
{
	this->y = y;
}

Model::Position::Position() : x(0), y(0)
{

}

Model::Position::Position(int x, int y) : x(x), y(y)
{

}

Model::Position::~Position()
{

}

Model::Position::Position(const Model::Position &rhs) : x(rhs.x), y(rhs.y)
{
	x = rhs.x;
	y = rhs.y;
}

Model::Position &Model::Position::operator=(const Model::Position &rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}
