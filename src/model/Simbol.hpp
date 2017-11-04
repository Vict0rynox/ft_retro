//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_SIMBOL_HPP
#define FT_RETRO_SIMBOL_HPP

#include <string>
#include "Position.hpp"

namespace Model {

	class Simbol {
	protected:
		std::string usim;
		Model::Position position;
	public:
		Simbol();
		~Simbol();
		Simbol(std::string usim, Model::Position position);
		Simbol(const Simbol &rhs);
		Simbol&operator=(const Simbol &rhs);

		std::string getUsim() const;

		void setUsim(std::string usim);

		const Position &getPosition() const;

		void setPosition(const Position &position);
	};
}
#endif //FT_RETRO_SIMBOL_HPP
