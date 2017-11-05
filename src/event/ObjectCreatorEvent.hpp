//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_OBJECTCREATE_HPP
#define FT_RETRO_OBJECTCREATE_HPP

#include "IEvent.hpp"
#include "../model/Object.hpp"
#include "../utils/List.hpp"
#include "../model/factory/IObjectFactory.hpp"

namespace Event {
	class ObjectCreatorEvent : public Event::IEvent{
	protected:
		Model::Factory::IObjectFactory *factory;
		Utils::List<Model::Object *> *objectsList;
		Utils::List<Event::IEvent *> *eventsList;
		time_t createTime;
		time_t duration;
	public:
		ObjectCreatorEvent();
		ObjectCreatorEvent(Utils::List<Model::Object *> *objectsList,
						   Utils::List<Event::IEvent *> *eventsList,
						   Model::Factory::IObjectFactory *factory,
						   time_t duration
		);
		~ObjectCreatorEvent();
		ObjectCreatorEvent(const ObjectCreatorEvent &rhs);
		ObjectCreatorEvent&operator=(const ObjectCreatorEvent &rhs);
		void handle();
		bool isEnd();
	};
}

#endif //FT_RETRO_OBJECTCREATE_HPP
