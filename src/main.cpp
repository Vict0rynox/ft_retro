//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ncurses.h>
#include <clocale>
#include "core/Application.hpp"
#include "control/ExitController.hpp"
#include "model/Player.hpp"
#include "view/ButtonKeyViewer.hpp"
#include "control/PlayerController.hpp"

int main()
{
	setlocale(LC_ALL, "");
	Core::Application *app = new Core::Application();

	Model::Player *player = new Model::Player("Player1", Model::Position(25,25));
	app->addObject(player);
	app->addController(new Control::ExitController(app));
	app->addController(new Control::PlayerController(player));
	app->addViewer(new View::ObjectViewer(app->getObjectsListPtr()));
	app->addViewer(new View::ButtonKeyViewer(app->getSimPtr(), Model::Position(0,0)));
	app->loop();
	return 0;
}