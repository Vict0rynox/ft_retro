//
// Created by Victor Vasiliev on 11/4/17.
//

#include "Simbol.hpp"

unsigned int Model::Simbol::getUsim() const
{
	return usim;
}

void Model::Simbol::setUsim(unsigned int usim)
{
	this->usim = usim;
}

const Model::Position &Model::Simbol::getPosition() const
{
	return position;
}

void Model::Simbol::setPosition(const Model::Position &position)
{
	this->position = position;
}

Model::Simbol::Simbol() : usim(0x0), position(Position())
{

}

Model::Simbol::~Simbol()
{

}

Model::Simbol::Simbol(const Model::Simbol &rhs) : usim(rhs.usim), position(rhs.position)
{

}

Model::Simbol &Model::Simbol::operator=(const Model::Simbol &rhs)
{
	usim = rhs.usim;
	position = rhs.position;
	return *this;
}

Model::Simbol::Simbol(unsigned int usim, Model::Position position) : usim(usim), position(position)
{

}
