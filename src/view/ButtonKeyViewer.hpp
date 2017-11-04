//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_BUTTONKEYVIEWER_HPP
#define FT_RETRO_BUTTONKEYVIEWER_HPP

#include "IViewer.hpp"
#include "../model/Position.hpp"
#include "../model/Size.hpp"

namespace View {
	class ButtonKeyViewer : public View::IViewer {
	protected:
		WINDOW *window;
		int *sim;
	public:
		ButtonKeyViewer();
		ButtonKeyViewer(int *sim);
		ButtonKeyViewer(int *sim, Model::Position position);
		~ButtonKeyViewer();
		ButtonKeyViewer(const ButtonKeyViewer &rhs);
		ButtonKeyViewer&operator=(const ButtonKeyViewer &rhs);
		void render();
	};
}

#endif //FT_RETRO_BUTTONKEYVIEWER_HPP
