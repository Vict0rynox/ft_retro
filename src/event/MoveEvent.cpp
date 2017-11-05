//
// Created by Victor Vasiliev on 11/5/17.
//

#include <ncurses.h>
#include "MoveEvent.hpp"

Event::MoveEvent::MoveEvent(Model::Object *object, int speed) : object(object), speed(speed)
{

}

Event::MoveEvent::MoveEvent() : object(), speed()
{

}

Event::MoveEvent::~MoveEvent()
{

}

Event::MoveEvent::MoveEvent(const Event::MoveEvent &rhs) : object(rhs.object), speed(rhs.speed)
{

}

Event::MoveEvent &Event::MoveEvent::operator=(const Event::MoveEvent &rhs)
{
	object = rhs.object;
	return *this;
}

void Event::MoveEvent::handle()
{
	if(!object->isDestroy()) {
		Model::Position newPos = Model::Position(object->getPosition().getX(),
												 object->getPosition().getY() + speed);
		object->setPosition(newPos);
	}
}

bool Event::MoveEvent::isEnd()
{
	return object->isDestroy();
}
