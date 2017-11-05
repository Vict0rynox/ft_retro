//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_ENEMIES_HPP
#define FT_RETRO_ENEMIES_HPP

#include "INcursesView.hpp"
#include "Unit.hpp"

namespace Model {
	class Enemies : public Model::INcursesView, public Model::Unit {
	protected:
		Utils::List<Model::Simbol> *view;
		Model::Size areaSize;
		int speed;
		int damage;
	public:
		Enemies();
		Enemies(std::string name, Model::Position position, int speed, int damage);
		~Enemies();
		Enemies(const Enemies &rhs);
		Enemies&operator=(const Enemies &rhs);
		Utils::List<Model::Simbol>* getView() const;
		const Model::Size& getAreaSize() const;
		int getSpeed() const;
	};
}


#endif //FT_RETRO_ENEMIES_HPP
