//
// Created by Victor Vasiliev on 11/5/17.
//

#include <ncurses.h>
#include "ObjectCreatorEvent.hpp"
#include "MoveEvent.hpp"
#include "../model/Unit.hpp"

void Event::ObjectCreatorEvent::handle()
{
	time_t currTime = time(NULL);
	if(currTime - createTime >= duration) {
		createTime = currTime;
		Model::Object *object = factory->createObject();
		if(dynamic_cast<Model::Unit*>(object) != nullptr){
			Model::Unit *unit = dynamic_cast<Model::Unit*>(object);
			eventsList->pushNode(new Event::MoveEvent(object, unit->getSpeed()));
		}
		objectsList->pushNode(object);
	}
}

bool Event::ObjectCreatorEvent::isEnd()
{
	return false;
}

Event::ObjectCreatorEvent::ObjectCreatorEvent(
		Utils::List<Model::Object *> *objectsList,
		Utils::List<Event::IEvent *> *eventsList,
		Model::Factory::IObjectFactory *factory,
        time_t duration
) :
	  factory(factory), objectsList(objectsList), eventsList(eventsList), createTime(), duration(duration)
{

}

Event::ObjectCreatorEvent::ObjectCreatorEvent() :
												  factory(), objectsList(), eventsList(), createTime(), duration(1)
{

}

Event::ObjectCreatorEvent::~ObjectCreatorEvent()
{

}

Event::ObjectCreatorEvent::ObjectCreatorEvent(
		const Event::ObjectCreatorEvent &rhs)
		: factory(rhs.factory), objectsList(rhs.objectsList), eventsList(rhs.eventsList), createTime(rhs.createTime),
		   duration(rhs.duration)
{

}

Event::ObjectCreatorEvent &
Event::ObjectCreatorEvent::operator=(const Event::ObjectCreatorEvent &rhs)
{
	objectsList = rhs.objectsList;
	createTime = rhs.createTime;
	duration = rhs.duration;
	factory = rhs.factory;
	return *this;
}
