//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_OBJECT_HPP
#define FT_RETRO_OBJECT_HPP

#include <string>
#include "Position.hpp"

namespace Model {

	class Object {
	protected:
		const std::string name;
		Model::Position position;
		bool isDestroyed;
		bool isNotIntersection;
	public:
		Object();
		virtual ~Object();
		explicit Object(const std::string &name, Model::Position position);
		Object(const Object &rhs);
		Object&operator=(const Object &rhs);
		const Model::Position& getPosition() const;
		const std::string& getName() const;
		void setPosition(Model::Position &position);
		bool isDestroy();
		void destroy();
		bool isIntersect(const Object &object);
		void setNotIntersection(bool notIntersection);
		bool isIsNotIntersection() const;
	};

}

#endif //FT_RETRO_OBJECT_HPP
