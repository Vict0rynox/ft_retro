//
// Created by Victor Vasiliev on 11/4/17.
//

#include "Unit.hpp"

Model::Unit::Unit(const std::string &name, Model::Position position,
				  int maxHealth, int damage)
	: Model::Object::Object(name, position), maxHealth(maxHealth), damage(damage)
{
	health = maxHealth;
	speed = 1;
}

Model::Unit::Unit() :
		Model::Object::Object("Unit", Model::Position(50,50)), maxHealth(100)
{
	health = maxHealth;
	damage = 10;
}

Model::Unit::~Unit()
{

}

Model::Unit::Unit(const Model::Unit &rhs) :
		Model::Object::Object(rhs.name, rhs.position), maxHealth(rhs.maxHealth), damage(rhs.damage)
{
	health = rhs.health;
}

Model::Unit &Model::Unit::operator=(const Model::Unit &rhs)
{
	position = rhs.position;
	health = rhs.health;
	damage = rhs.damage;
	return *this;
}

int Model::Unit::getMaxHealth() const
{
	return maxHealth;
}

const int& Model::Unit::getHealth() const
{
	return health;
}

const int& Model::Unit::getDamage() const
{
	return damage;
}

void Model::Unit::setDamage(int damage)
{
	this->damage = damage;
}

int Model::Unit::getSpeed() const
{
	return speed;
}

Model::Unit::Unit(const std::string &name, Model::Position position,
				  int maxHealth, int speed, int damage)
		: Model::Object::Object(name, position), maxHealth(maxHealth), damage(damage), speed(speed)
{
	health = maxHealth;
}
