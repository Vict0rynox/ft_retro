//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>
#include "ButtonKeyViewer.hpp"

View::ButtonKeyViewer::ButtonKeyViewer() : window(newwin(3,15,0,0)), sim()
{

}

View::ButtonKeyViewer::~ButtonKeyViewer()
{
	delwin(window);
}

View::ButtonKeyViewer::ButtonKeyViewer(const View::ButtonKeyViewer &rhs) : window(rhs.window), sim(rhs.sim)
{

}

View::ButtonKeyViewer &
View::ButtonKeyViewer::operator=(const View::ButtonKeyViewer &rhs)
{
	sim = rhs.sim;
	window = rhs.window;
	return *this;
}

View::ButtonKeyViewer::ButtonKeyViewer(int *sim, Model::Position position)
		:  window(newwin(3, 15, position.getY(), position.getX())), sim(sim)
{

}

void View::ButtonKeyViewer::render()
{
	werase(window);
	mvwprintw(window,1,3, "%c[%d]", *sim, *sim);
	box(window, 0, 0);
	wrefresh(window);
}

View::ButtonKeyViewer::ButtonKeyViewer(int *sim) :  window(newwin(3, 15, 0,0)), sim(sim)
{

}
