//
// Created by Victor Vasiliev on 11/5/17.
//

#include "FPSViewer.hpp"

View::FPSViewer::FPSViewer() : tickRate(), window()
{

}

View::FPSViewer::~FPSViewer()
{
	delwin(window);
}

View::FPSViewer::FPSViewer(const View::FPSViewer &rhs) :tickRate(rhs.tickRate), window(rhs.window)
{

}

void View::FPSViewer::render()
{
	werase(window);
	mvwprintw(window,1,3, "FPS:%f", tickRate->getAverageFrameTimeMilliseconds());
	box(window, 0, 0);
	wrefresh(window);
}

View::FPSViewer::FPSViewer(Core::TickRate *tickRate, Model::Position position) : tickRate(tickRate), window(newwin(3, 30, position.getY(), position.getX()))
{

}

View::FPSViewer::FPSViewer(Core::TickRate *tickRate) : tickRate(tickRate), window(newwin(3, 30, 0, 0))
{

}

View::FPSViewer &View::FPSViewer::operator=(const View::FPSViewer &rhs)
{
	window = rhs.window;
	tickRate = rhs.tickRate;
	return *this;
}
