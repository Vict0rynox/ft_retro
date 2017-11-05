//
// Created by Victor Vasiliev on 11/5/17.
//

#include <ncurses.h>
#include "GameOverEvent.hpp"

Event::GameOverEvent::GameOverEvent() : player(){

}

Event::GameOverEvent::~GameOverEvent() {

}

Event::GameOverEvent &Event::GameOverEvent::operator=(const Event::GameOverEvent &rhs) {
    player = rhs.player;
    return *this;
}

Event::GameOverEvent::GameOverEvent(const Event::GameOverEvent &rhs) : player(rhs.player){

}

void Event::GameOverEvent::handle() {
    if(player != nullptr && player->isDestroy()) {
        int x, y;
        getmaxyx(stdscr, y, x);
        WINDOW *window = newwin(y/2, x/2, y/4, x/4);
        getmaxyx(window, y, x);
        mvwprintw(window, y/2, x/4, "Game Over.");
        mvwprintw(window, y/2+1, x/4, "Pres any to exit.");
        box(window, 0, 0);
        wrefresh(window);
        nocbreak();
        getch();
        endwin();
        exit(0);
    }
}

bool Event::GameOverEvent::isEnd() {
    return false;
}

Event::GameOverEvent::GameOverEvent(Model::Player *player) : player(player) {

}
