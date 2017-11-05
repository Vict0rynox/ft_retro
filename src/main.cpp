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
#include "view/FPSViewer.hpp"
#include "event/MoveEvent.hpp"
#include "model/Bullet.hpp"
#include "model/factory/UnitFactory.hpp"
#include "model/Stars.hpp"
#include "event/ObjectCreatorEvent.hpp"
#include "model/Enemies.hpp"
#include "event/GameOverEvent.hpp"

int main()
{
	setlocale(LC_ALL, "");
	Core::Application *app = new Core::Application();
	Model::Player *player = new Model::Player("Player1", Model::Position(25,25));
	Model::Factory::IObjectFactory *starsFactory = new Model::Factory::UnitFactory<Model::Stars>("Starts");
	Model::Factory::IObjectFactory *enemiesFactory = new Model::Factory::UnitFactory<Model::Enemies>("Enemies");

	app->addObject(player);
	app->addController(new Control::ExitController(app));
	app->addController(new Control::PlayerController(player,app->getEventsListPtr() ,app->getObjectsListPtr()));
	app->addViewer(new View::ObjectViewer(app->getObjectsListPtr()));
	app->addViewer(new View::ButtonKeyViewer(app->getSimPtr(), Model::Position(0,0)));
	app->addViewer(new View::FPSViewer(app->getTickRatePtr(), Model::Position(20,0)));
	app->addEvent(new Event::ObjectCreatorEvent(app->getObjectsListPtr(), app->getEventsListPtr(), starsFactory, 0));
	app->addEvent(new Event::ObjectCreatorEvent(app->getObjectsListPtr(), app->getEventsListPtr(), enemiesFactory, 1));
	app->addEvent(new Event::GameOverEvent(player));
	app->loop();
	return 0;
}