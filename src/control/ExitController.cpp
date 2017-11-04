//
// Created by Victor Vasiliev on 11/4/17.
//

#include "ExitController.hpp"

Control::ExitController::~ExitController()
{

}

Control::ExitController::ExitController() : Control::BaseController(27), app(nullptr)
{

}

Control::ExitController::ExitController(const Control::ExitController &rhs) : Control::BaseController(rhs), app(rhs.app)
{

}

Control::ExitController &
Control::ExitController::operator=(const Control::ExitController &rhs)
{
	Control::BaseController::operator=(rhs);
	this->app = rhs.app;
	return *this;
}

void Control::ExitController::handle(int buttonCode)
{
	if(isHandle(buttonCode)) { //because has only node button
		this->app->exit();
	}
}

Control::ExitController::ExitController(Core::Application *app) : Control::BaseController(27), app(app)
{

}
