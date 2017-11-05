//
// Created by Victor Vasiliev on 11/5/17.
//

#include "FPSViewer.hpp"

View::FPSViewer::FPSViewer() :  window(), tickRate()
{

}

View::FPSViewer::~FPSViewer()
{
	delwin(window);
}

View::FPSViewer::FPSViewer(const View::FPSViewer &rhs) :window(rhs.window), tickRate(rhs.tickRate)
{

}

void View::FPSViewer::render()
{
	werase(window);
	mvwprintw(window,1,3, "FPS:%f", tickRate->getFps());
	box(window, 0, 0);
	wrefresh(window);
}

View::FPSViewer::FPSViewer(Core::TickRate *tickRate, Model::Position position)
		: window(newwin(3, 30, position.getY(), position.getX())), tickRate(tickRate)
{

}

View::FPSViewer::FPSViewer(Core::TickRate *tickRate)
		: window(newwin(3, 30, 0, 0)), tickRate(tickRate)
{

}

View::FPSViewer &View::FPSViewer::operator=(const View::FPSViewer &rhs)
{
	window = rhs.window;
	tickRate = rhs.tickRate;
	return *this;
}
