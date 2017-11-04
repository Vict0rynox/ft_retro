//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>
#include "Application.hpp"

void Core::Application::loop()
{
	while (!isExit) { //loop
		tickRate.calcFps();
		if(tickRate.getFps() >= minFPS && tickRate.getFps() <= maxFPS) {
			control();
			update();
			redrow();
		}
	}
}

void Core::Application::control()
{
	int x,y;
	sim = getch();
	if(sim == 27) {
		isExit = true;
	}
	getmaxyx(stdscr, x, y);
	winSize.setHeight(y);
	winSize.setHeight(x);
}

void Core::Application::update()
{
	mvprintw(winSize.getHeight()/2, winSize.getWidth()/2, "%c[%d]", sim, sim);
}

void Core::Application::redrow()
{
	refresh();
}

Core::Application::Application(const Core::Application &rhs)
		: maxFPS(rhs.maxFPS), minFPS(rhs.minFPS), isExit(rhs.isExit)
{
	_init();
}

Core::Application &Core::Application::operator=(const Core::Application &rhs)
{
	isExit = rhs.isExit;
	return *this;
}

Core::Application::Application() : maxFPS(33), minFPS(29), isExit(false)
{
	_init();
}

Core::Application::~Application()
{
	endwin();
}

void Core::Application::_init()
{
	initscr();
	noecho();
}
