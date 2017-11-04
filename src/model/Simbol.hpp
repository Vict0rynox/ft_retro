//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_SIMBOL_HPP
#define FT_RETRO_SIMBOL_HPP

#include "Position.hpp"

namespace Model {

	class Simbol {
	protected:
		unsigned int usim;
		Model::Position position;
	public:
		Simbol();
		~Simbol();
		Simbol(unsigned int usim, Model::Position position);
		Simbol(const Simbol &rhs);
		Simbol&operator=(const Simbol &rhs);

		unsigned int getUsim() const;

		void setUsim(unsigned int usim);

		const Position &getPosition() const;

		void setPosition(const Position &position);
	};
}
#endif //FT_RETRO_SIMBOL_HPP
