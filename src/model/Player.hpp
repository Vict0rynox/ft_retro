//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_PLAYER_HPP
#define FT_RETRO_PLAYER_HPP

#include "INcursesView.hpp"
#include "Unit.hpp"
#include "Simbol.hpp"
#include "Size.hpp"

namespace Model {
	class Player : virtual Model::INcursesView, public Model::Unit{
	protected:
		Utils::List<Model::Simbol> view;
		Model::Size areaSize;
	public:
		Player();
		Player(std::string name, Model::Position position);
		~Player();
		Player(const Player &rhs);
		Player&operator=(const Player &rhs);
		const Utils::List<Model::Simbol>& getView() const;
		const Model::Size& getAreaSize() const;
	};
}


#endif //FT_RETRO_PLAYER_HPP
