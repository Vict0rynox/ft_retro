//
// Created by Victor Vasiliev on 11/4/17.
//

#include "Size.hpp"

unsigned int Model::Size::getWidth() const
{
	return width;
}

void Model::Size::setWidth(unsigned int width)
{
	Size::width = width;
}

unsigned int Model::Size::getHeight() const
{
	return height;
}

void Model::Size::setHeight(unsigned int height)
{
	Size::height = height;
}

Model::Size::Size() : width(0), height(0)
{

}

Model::Size::~Size()
{

}

Model::Size::Size(unsigned int width, unsigned int height) : width(width), height(height)
{

}

Model::Size::Size(const Model::Size &rhs): width(rhs.width), height(rhs.height)
{

}

Model::Size &Model::Size::operator=(const Model::Size &rhs)
{
	height = rhs.height;
	width = rhs.width;
	return *this;
}
