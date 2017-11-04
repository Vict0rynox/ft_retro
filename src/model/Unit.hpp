//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_UNIT_HPP
#define FT_RETRO_UNIT_HPP

#include <string>
#include "Object.hpp"
#include "Position.hpp"

namespace Model {

	class Unit : public Object {
	protected:
		const int maxHealth;
		int health;
		int damage;
	public:
		Unit();
		~Unit();
		Unit(const std::string &name, Model::Position position, int maxHealth, int damage);
		Unit(const Unit &rhs);
		Unit&operator=(const Unit &rhs);
		const int getMaxHealth() const;
		const int& getHealth() const;
		const int& getDamage() const;
		void setDamage(int damage);
	};
}

#endif //FT_RETRO_UNIT_HPP
