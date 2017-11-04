//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_IVIEW_HPP
#define FT_RETRO_IVIEW_HPP


#include "Object.hpp"
#include "../utils/List.hpp"
#include "Simbol.hpp"
#include "Size.hpp"

namespace Model{

	class INcursesView {
	public:
		virtual const Utils::List<Model::Simbol>& getView() const = 0;
		virtual const Model::Size& getAreaSize() const = 0;
	};
}

#endif //FT_RETRO_IVIEW_HPP
