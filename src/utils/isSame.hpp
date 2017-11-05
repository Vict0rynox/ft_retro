//
// Created by Victor Vasiliev on 11/5/17.
//

#ifndef FT_RETRO_ISSAME_HPP
#define FT_RETRO_ISSAME_HPP

namespace Utils {
	template<class T, class U>
	struct is_same
	{
		static const bool value = false;
	};

	template<class T>
	struct is_same<T, T>
	{
		static const bool value = true;
	};
}
#endif //FT_RETRO_ISSAME_HPP
