//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_ICONTROLLER_HPP
#define FT_RETRO_ICONTROLLER_HPP

namespace Control
{
	class IController {
	public:
		virtual bool isHandle(int buttonCode) = 0;
		virtual void handle(int buttonCode) = 0;
	};
}


#endif //FT_RETRO_ICONTROLLER_HPP
