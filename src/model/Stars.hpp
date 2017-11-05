//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_STARS_HPP
#define FT_RETRO_STARS_HPP


#include "INcursesView.hpp"
#include "Unit.hpp"

namespace Model {
	class Stars : public Model::INcursesView, public Model::Unit {
	protected:
		Utils::List<Model::Simbol> *view;
		Model::Size areaSize;
		int speed;
		int damage;
	public:
		Stars();
		Stars(std::string name, Model::Position position, int speed, int damage);
		~Stars();
		Stars(const Stars &rhs);
		Stars&operator=(const Stars &rhs);
		Utils::List<Model::Simbol>* getView() const;
		const Model::Size& getAreaSize() const;
		int getSpeed() const;
	};
}



#endif //FT_RETRO_STARS_HPP
