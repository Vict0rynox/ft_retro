//
// Created by Victor Vasiliev on 11/4/17.
//

#include "Object.hpp"
#include "Position.hpp"

Model::Object::Object() : name("Object"), position(Model::Position(0,0)), isDestroyed(false)
{

}

Model::Object::~Object()
{

}

Model::Object::Object(const std::string &name,  Model::Position position)
		: name(name), position(position)
{

}

Model::Object::Object(const Model::Object &rhs)
		: name(rhs.name), position(rhs.position), isDestroyed(rhs.isDestroyed)
{

}

Model::Object &Model::Object::operator=(const Model::Object &rhs)
{
	position = rhs.position;
	isDestroyed = rhs.isDestroyed;

	return *this;
}

const Model::Position &Model::Object::getPosition() const
{
	return position;
}

const std::string &Model::Object::getName() const
{
	return name;
}

void Model::Object::setPosition(Model::Position &position)
{
	this->position = position;
}

bool Model::Object::isDestroy()
{
	return isDestroyed;
}

void Model::Object::destroy()
{
	isDestroyed = true;
}


