//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_SIZE_HPP
#define FT_RETRO_SIZE_HPP

namespace Model {
	class Size {
	protected:
		unsigned int width;
		unsigned int height;
	public:
		Size();
		~Size();
		Size(unsigned int width, unsigned int height);
		Size(const Size &rhs);
		Size&operator=(const Size &rhs);

		unsigned int getWidth() const;

		void setWidth(unsigned int width);

		unsigned int getHeight() const;

		void setHeight(unsigned int height);
	};
}

#endif //FT_RETRO_SIZE_HPP
