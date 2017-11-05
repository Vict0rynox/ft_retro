//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_IOBJECTFACTORY_HPP
#define FT_RETRO_IOBJECTFACTORY_HPP

#include "../Object.hpp"

namespace Model {
	namespace Factory {
		class IObjectFactory {
		public:
			virtual ~IObjectFactory();

			virtual Model::Object *createObject() = 0;
		};
	}
}


#endif //FT_RETRO_IOBJECTFACTORY_HPP
