//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_APPLICATION_HPP
#define FT_RETRO_APPLICATION_HPP

#include <ncurses.h>
#include <zconf.h>
#include "TickRate.hpp"
#include "../model/Size.hpp"
#include "../utils/List.hpp"
#include "../control/IController.hpp"
#include "../model/Object.hpp"
#include "../view/ObjectViewer.hpp"


namespace Core {
	class Application {
	private:
		void _init();
		Model::Size winSize;
		int sim;
		WINDOW *window;
	protected:
		Utils::List<Control::IController*> controllerList;
		Utils::List<Model::Object*> objectsList;
		Utils::List<View::IViewer*> viewerList;
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
		void addObject(Model::Object *object);
		void addViewer(View::IViewer *viewer);
		void exit();
		void changed();

		//getter
		Utils::List<Model::Object *> *getObjectsListPtr();
		int *getSimPtr();
	};
}


#endif //FT_RETRO_APPLICATION_HPP
