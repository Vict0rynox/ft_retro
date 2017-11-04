//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_IITERRATOR_HPP
#define FT_RETRO_IITERRATOR_HPP

namespace Utils
{
	template <class T>
	class IIterrator {
	public:
		virtual T curr() = 0;
		virtual bool isEnd() = 0;
		virtual void next() = 0;
		virtual void prev() = 0;
		virtual void reset() = 0;
	};
}

#endif //FT_RETRO_IITERRATOR_HPP
