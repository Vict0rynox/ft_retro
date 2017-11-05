//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_IEVENT_HPP
#define FT_RETRO_IEVENT_HPP

namespace Event {

	class IEvent {
	public:
		//virtual ~IEvent();
		virtual void handle() = 0;
		virtual bool isEnd() = 0;
	};

}
#endif //FT_RETRO_IEVENT_HPP
