//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_APPLICATION_HPP
#define FT_RETRO_APPLICATION_HPP


#include <zconf.h>
#include "TickRate.hpp"
#include "../model/Size.hpp"
#include "../utils/List.hpp"
#include "../control/IController.hpp"


namespace Core {
	class Application;

	typedef void (Application::*exitFunc)();

	class Application {
	private:
		void _init();
		Model::Size winSize;
		int sim;
	protected:
		Utils::List<Control::IController*> controllerList;
		bool isExit;
		bool isChange;
		const float minFPS;
		const float maxFPS;

		Core::TickRate tickRate;

		void control();
		void update();
		void redrow();
	public:
		Application();
		~Application();
		Application(const Application &rhs);
		Application&operator=(const Application &rhs);
		void loop();
		void addController(Control::IController *controller);
		void exit();
		void changed();
	};
}


#endif //FT_RETRO_APPLICATION_HPP
