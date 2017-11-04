//
// Created by Victor Vasiliev on 11/4/17.
//

#include <ctime>
#include "TickRate.hpp"

clock_t Core::TickRate::getOldTick() const
{
	return oldTick;
}

clock_t Core::TickRate::getCurTick() const
{
	return curTick;
}

clock_t Core::TickRate::getElapsedTime() const
{
	return elapsedTime;
}

clock_t Core::TickRate::getFrame() const
{
	return frame;
}

float Core::TickRate::getFps() const
{
	return fps;
}

Core::TickRate::TickRate() : oldTick(0), curTick(0), elapsedTime(0), frame(0), fps(0)
{

}

Core::TickRate::~TickRate()
{

}

Core::TickRate &Core::TickRate::operator=(const Core::TickRate &rhs)
{
	oldTick =rhs.oldTick;
	curTick =rhs.curTick;
	elapsedTime =rhs.elapsedTime;
	frame =rhs.frame;
	fps= rhs.fps;
	return *this;
}

Core::TickRate::TickRate(const Core::TickRate &rhs)
		: oldTick(rhs.oldTick), curTick(rhs.curTick),
		  elapsedTime(rhs.elapsedTime), frame(rhs.frame), fps(rhs.fps)
{

}

void Core::TickRate::calcFps()
{
	clock_t deltaTick;

	oldTick = curTick;
	curTick = static_cast<int>(clock());
	deltaTick = curTick - oldTick;
	elapsedTime += deltaTick;
	frame++;
	fps = ((float)frame / (float)elapsedTime) * 1000000;
}
