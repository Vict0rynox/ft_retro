//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_GAMEOVEREVENT_H
#define FT_RETRO_GAMEOVEREVENT_H

#include "../model/Player.hpp"
#include "IEvent.hpp"

namespace Event {
    class GameOverEvent : public Event::IEvent{
    protected:
        Model::Player *player;
    public:
        GameOverEvent();
        GameOverEvent(Model::Player *player);
        ~GameOverEvent();
        GameOverEvent(const GameOverEvent &rhs);
        GameOverEvent&operator=(const GameOverEvent &rhs);
        void handle();
        bool isEnd();
    };
}

#endif //FT_RETRO_GAMEOVEREVENT_H
