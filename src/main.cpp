//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>
#include <clocale>
#include "core/Application.hpp"
#include "control/ExitController.hpp"
#include "model/Player.hpp"

int main()
{
	setlocale(LC_ALL, "");
	Core::Application *app = new Core::Application();

	app->addObject(new Model::Player("Player1", Model::Position(25,25)));
	app->addController(new Control::ExitController(app));
	app->addViewer(new View::ObjectViewer(app->getObjectsList()));
	app->loop();
	return 0;
}