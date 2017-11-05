//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_BULLET_HPP
#define FT_RETRO_BULLET_HPP

#include "INcursesView.hpp"
#include "Unit.hpp"

namespace Model {
	class Bullet : public Model::INcursesView, public Model::Unit {
	protected:
		Utils::List<Model::Simbol> *view;
		Model::Size areaSize;
		int speed;
		int damage;
	public:
		Bullet();
		Bullet(std::string name, Model::Position position, int speed, int damage);
		~Bullet();
		Bullet(const Bullet &rhs);
		Bullet&operator=(const Bullet &rhs);
		Utils::List<Model::Simbol>* getView() const;
		const Model::Size& getAreaSize() const;
		int getSpeed() const;
		int getDamage() const;
	};
}
#endif //FT_RETRO_BULLET_HPP
