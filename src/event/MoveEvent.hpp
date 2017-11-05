//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_MOVEEVENT_HPP
#define FT_RETRO_MOVEEVENT_HPP

#include "IEvent.hpp"
#include "../model/Object.hpp"

namespace Event {
	class MoveEvent : public Event::IEvent{
	protected:
		Model::Object *object;
		int speed;
	public:
		MoveEvent();
		MoveEvent(Model::Object *object, int speed);
		virtual ~MoveEvent();
		MoveEvent(const MoveEvent &rhs);
		MoveEvent&operator=(const MoveEvent &rhs);

		void handle();
		bool isEnd();
	};
}

#endif //FT_RETRO_MOVEEVENT_HPP
