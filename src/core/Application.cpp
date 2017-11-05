//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>
#include <zconf.h>
#include <cmath>
#include "Application.hpp"
#include "../model/INcursesView.hpp"

void Core::Application::loop()
{
	while (!isExit) { //loop
		tickRate.calcFps();
		double sleepTime = 0;
		if (tickRate.getFps() <= maxFPS) {
			control();
			update();
			redrow();
		}
	}
	endwin();
}

void Core::Application::control()
{
	sim = getch(); //get button
	int x, y;
	getmaxyx(stdscr, y, x);
	winSize.setHeight(static_cast<unsigned int>(y));
	winSize.setWidth(static_cast<unsigned int>(x));
}

void Core::Application::update()
{
	Control::IController *controller;
	while (!controllerList.isEnd()) {
		controller = controllerList.curr();
		if (controller->isHandle(sim)) {
			controller->handle(sim);
			changed();
		}
		controllerList.prev();
	}
	controllerList.reset();
}

void Core::Application::redrow()
{

	View::IViewer *viewer;
	while (!viewerList.isEnd()) {

		viewer = viewerList.curr();
		viewer->render();
		viewerList.prev();
	}
	viewerList.reset();
	refresh();
}

Core::Application::Application(const Core::Application &rhs)
		: maxFPS(rhs.maxFPS), minFPS(rhs.minFPS), sim(), isExit(rhs.isExit),
		  isChange(rhs.isChange)
{
	_init();
}

Core::Application &Core::Application::operator=(const Core::Application &rhs)
{
	isExit = rhs.isExit;
	isChange = rhs.isChange;
	return *this;
}

Core::Application::Application() : maxFPS(200), minFPS(29), sim(), isExit(false),
								   isChange(false)
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
	curs_set(0);
	raw();
	noecho();
	keypad(stdscr, true);
	halfdelay(1);
	control();
}

void Core::Application::addController(Control::IController *controller)
{
	controllerList.pushNode(controller);
}

void Core::Application::exit()
{
	isExit = true;
}

void Core::Application::changed()
{
	isChange = true;
}

void Core::Application::addObject(Model::Object *object)
{
	objectsList.pushNode(object);
}

void Core::Application::addViewer(View::IViewer *viewer)
{
	viewerList.pushNode(viewer);
}

Utils::List<Model::Object *> *Core::Application::getObjectsListPtr()
{
	return &objectsList;
}

int *Core::Application::getSimPtr()
{
	return &sim;
}

Core::TickRate *Core::Application::getTickRatePtr()
{
	return &tickRate;
}
