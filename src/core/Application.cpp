//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>
#include "Application.hpp"
#include "../model/INcursesView.hpp"

void Core::Application::loop()
{
	while (!isExit) { //loop
		tickRate.calcFps();
		//if(tickRate.getFps() >= minFPS && tickRate.getFps() <= maxFPS) {
		control();
		erase();
		update();
		redrow();
		//}
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
	mvprintw(winSize.getHeight() / 2, winSize.getWidth() / 2, "%c[%d]", sim, sim);

	Control::IController *controller;
	while (!controllerList.isEnd()) {
		controller = controllerList.curr();
		if (controller->isHandle(sim)) {
			controller->handle(sim);
			changed();
		}
		controllerList.next();
	}
	controllerList.reset();
}

void Core::Application::redrow()
{

	View::IViewer *viewer;
	while (!viewerList.isEnd()) {
		viewer = viewerList.curr();
		viewer->render();
		viewerList.next();
	}
	viewerList.reset();
	refresh();
}

Core::Application::Application(const Core::Application &rhs)
		: maxFPS(rhs.maxFPS), minFPS(rhs.minFPS), isExit(rhs.isExit),
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

Core::Application::Application() : maxFPS(33), minFPS(29), isExit(false),
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
	raw();
	noecho();
	keypad(stdscr, true);
	halfdelay(1);
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

Utils::List<Model::Object *> *Core::Application::getObjectsList()
{
	return &objectsList;
}
