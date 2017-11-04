//
// Created by Victor Vasiliev on 11/4/17.
//

#include "Simbol.hpp"

std::string Model::Simbol::getUsim() const
{
	return usim;
}

void Model::Simbol::setUsim(std::string usim)
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

Model::Simbol::Simbol() : usim(""), position(Position())
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

Model::Simbol::Simbol(std::string usim, Model::Position position) : usim(usim), position(position)
{

}
