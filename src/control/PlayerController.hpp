//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_PLAYERCONTROLLER_HPP
#define FT_RETRO_PLAYERCONTROLLER_HPP

#include "IController.hpp"
#include "../model/Player.hpp"

namespace Control {
	class PlayerController : public Control::IController {
	protected:
		const int moveUpButtonKeyCode;
		const int moveDownButtonKeyCode;
		const int moveLeftButtonKeyCode;
		const int moveRightButtonKeyCode;
		const int shootButtonKeyCode;
		Model::Player *player;
	public:
		PlayerController();
		PlayerController(Model::Player *player);
		PlayerController(const PlayerController &rhs);
		PlayerController&operator=(const PlayerController &rhs);

		~PlayerController();

		PlayerController(Model::Player *player, int moveUpButtonKeyCode, int moveDownButtonKeyCode,
						 int moveLeftButtonKeyCode, int moveRightButtonKeyCode,
						 int shootButtonKeyCode);

		bool isHandle(int buttonCode);

		void handle(int buttonCode);
	};
}
#endif //FT_RETRO_PLAYERCONTROLLER_HPP
