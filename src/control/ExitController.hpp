//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_EXITCONTROLLER_HPP
#define FT_RETRO_EXITCONTROLLER_HPP

#include "BaseController.hpp"
#include "../core/Application.hpp"

namespace Control
{
	class ExitController : public Control::BaseController {
	protected:
		Core::Application *app;
	public:
		ExitController();
		ExitController(Core::Application *app);
		virtual ~ExitController();
		ExitController(const ExitController &rhs);
		ExitController&operator=(const ExitController &rhs);
		void handle(int buttonCode);
	};
}

#endif //FT_RETRO_EXITCONTROLLER_HPP
