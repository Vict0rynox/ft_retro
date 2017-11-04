//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_APPLICATION_HPP
#define FT_RETRO_APPLICATION_HPP


#include <zconf.h>
#include "TickRate.hpp"
#include "../model/Size.hpp"


namespace Core {
	class Application {
	private:
		void _init();
		Model::Size winSize;
		int sim;
	protected:
		bool isExit;
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
	};
}


#endif //FT_RETRO_APPLICATION_HPP
