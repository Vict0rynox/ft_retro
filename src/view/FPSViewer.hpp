//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_FPSVIEWER_HPP
#define FT_RETRO_FPSVIEWER_HPP

#include <ncurses.h>
#include "IViewer.hpp"
#include "../core/TickRate.hpp"
#include "../model/Position.hpp"

namespace View {
	class FPSViewer : public View::IViewer {
	protected:
		WINDOW *window;
		Core::TickRate *tickRate;
	public:
		FPSViewer();
		FPSViewer(Core::TickRate *tickRate);
		FPSViewer(Core::TickRate *tickRate, Model::Position position);
		~FPSViewer();
		FPSViewer(const FPSViewer &rhs);
		FPSViewer&operator=(const FPSViewer &rhs);
		void render();
	};
}


#endif //FT_RETRO_FPSVIEWER_HPP
