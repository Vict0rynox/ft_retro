//
// Created by Victor Vasiliev on 11/4/17.
//

#include "BaseController.hpp"

bool Control::BaseController::isHandle(int buttonCode)
{
	return (buttonKeyCode == buttonCode);
}

void Control::BaseController::handle(int buttonCode)
{
	(void)buttonCode;
}

Control::BaseController::BaseController() : buttonKeyCode()
{

}

Control::BaseController::~BaseController()
{

}

Control::BaseController::BaseController(int buttonKeyCode) : buttonKeyCode(buttonKeyCode)
{

}

Control::BaseController::BaseController(const Control::BaseController &rhs): buttonKeyCode(rhs.buttonKeyCode)
{

}

Control::BaseController &
Control::BaseController::operator=(const Control::BaseController &rhs)
{
	(void)rhs;
	return *this;
}
