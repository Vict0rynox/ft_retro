//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_POSITION_HPP
#define FT_RETRO_POSITION_HPP

namespace Model
{
	class Position {
	protected:
		int x;
		int y;
	public:
		Position();
		~Position();
		Position(int x, int y);
		Position(const Position &rhs);
		Position&operator=(const Position &rhs);

		int getX() const;

		void setX(int x);

		int getY() const;

		void setY(int y);

	};
}

#endif //FT_RETRO_POSITION_HPP
