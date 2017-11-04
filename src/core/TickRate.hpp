//
// Created by Victor Vasiliev on 11/4/17.
//

#ifndef FT_RETRO_TICKRATE_HPP
#define FT_RETRO_TICKRATE_HPP

namespace Core {
	class TickRate {
	protected:
		clock_t oldTick;
		clock_t curTick;
		clock_t elapsedTime;
		clock_t frame;
		float fps;
	public:
		TickRate();

		~TickRate();

		TickRate(const TickRate &rhs);

		TickRate &operator=(const TickRate &rhs);

		clock_t getOldTick() const;

		clock_t getCurTick() const;

		clock_t getElapsedTime() const;

		clock_t getFrame() const;

		float getFps() const;

		void calcFps();
	};
}

#endif //FT_RETRO_TICKRATE_HPP
