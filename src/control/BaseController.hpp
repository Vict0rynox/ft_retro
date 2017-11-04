//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_BASECONTROLLER_HPP
#define FT_RETRO_BASECONTROLLER_HPP

#include "IController.hpp"

namespace Control
{
	class BaseController : public Control::IController{
	protected:
		const int buttonKeyCode;
	public:
		bool isHandle(int buttonCode);
		void handle(int buttonCode);
		BaseController();

		virtual ~BaseController();
		explicit BaseController(int buttonKeyCode);
		BaseController(const BaseController &rhs);
		BaseController&operator=(const BaseController &rhs);

	};
}

#endif //FT_RETRO_EXITCONTROLLER_HPP
