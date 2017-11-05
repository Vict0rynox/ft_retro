//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_UNITFACTORY_HPP
#define FT_RETRO_UNITFACTORY_HPP


#include <ncurses.h>
#include "../Object.hpp"
#include "IObjectFactory.hpp"
#include "../Unit.hpp"
#include "../../utils/isSame.hpp"

namespace Model {
	namespace Factory {
		template <class T>
		class UnitFactory : public IObjectFactory {
		protected:
			std::string objectName;
		public:
			UnitFactory();
			UnitFactory(std::string objectName);
			UnitFactory(const UnitFactory& rhs);
			UnitFactory&operator=(const UnitFactory& rhs);
			~UnitFactory();
			Model::Object *createObject();
		};

		template<class T>
		UnitFactory<T>::UnitFactory()
		{
			if(Utils::is_same<T, Model::Unit>::value) {
				throw std::invalid_argument("Type mast be a Unit comparable.");
			}
			srand(static_cast<unsigned int>(time(NULL) + clock()));
		}

		template<class T>
		UnitFactory<T>::UnitFactory(const UnitFactory<T> &rhs)
		{
			(void)rhs;
		}

		template<class T>
		UnitFactory<T>::~UnitFactory()
		{

		}

		template<class T>
		UnitFactory<T> &UnitFactory<T>::operator=(const UnitFactory<T> &rhs)
		{
			(void)rhs;
			return *this;
		}

		template<class T>
		Model::Object *UnitFactory<T>::createObject()
		{
			int x = 1 + (rand() % static_cast<int>(getmaxx(stdscr) - 1 + 1));
			Model::Position pos = Model::Position(x, 3);
			return new T(objectName, pos, 1, 0);
		}

		template<class T>
		UnitFactory<T>::UnitFactory(std::string objectName) : objectName(objectName)
		{

		}
	}
}



#endif //FT_RETRO_UNITFACTORY_HPP
