//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ctime>
#include <cstdlib>
#include "TickRate.hpp"

clock_t Core::TickRate::getOldTick() const
{
	return oldTick;
}

clock_t Core::TickRate::getCurTick() const
{
	return curTick;
}

float Core::TickRate::getFps() const
{
	return fps;
}

Core::TickRate::TickRate() : oldTick(0), curTick(0), fps()
{

}

Core::TickRate::~TickRate()
{

}

Core::TickRate &Core::TickRate::operator=(const Core::TickRate &rhs)
{
	oldTick =rhs.oldTick;
	curTick =rhs.curTick;
	fps= rhs.fps;
	return *this;
}

Core::TickRate::TickRate(const Core::TickRate &rhs)
		: oldTick(rhs.oldTick), curTick(rhs.curTick),
		  fps(rhs.fps)
{

}

void Core::TickRate::calcFps()
{
	float deltaTick;
	oldTick = curTick;
	curTick = clock();
	deltaTick = curTick - oldTick;
	fps = (float)CLOCKS_PER_SEC / deltaTick;
}

