//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_TICKRATE_HPP
#define FT_RETRO_TICKRATE_HPP

#include <ctime>

namespace Core {
	class TickRate {
	protected:
		clock_t oldTick;
		clock_t curTick;
		float fps;
		double averageFrameTimeMilliseconds;
		float deltaTick;
		long frame;
	public:
		TickRate();

		double getAverageFrameTimeMilliseconds() const;

		~TickRate();

		TickRate(const TickRate &rhs);

		TickRate &operator=(const TickRate &rhs);

		clock_t getOldTick() const;

		clock_t getCurTick() const;

		float getFps() const;

		void calcFps();
	};
}

#endif //FT_RETRO_TICKRATE_HPP
