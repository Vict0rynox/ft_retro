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

Core::TickRate::TickRate() : oldTick(0), curTick(0), fps(10),
							 deltaTick()
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
		  fps(rhs.fps), deltaTick()
{

}

void Core::TickRate::calcFps()
{
	double milisecond;
	oldTick = curTick;
	curTick = clock();
	deltaTick += curTick - oldTick;
	frame++;

	milisecond = (deltaTick / (double)CLOCKS_PER_SEC) * 1000.0;
	if(milisecond > 1000.0) {
		fps = static_cast<float>((float)frame * 0.5 + fps * 0.5);
		frame = 0;
		deltaTick -= CLOCKS_PER_SEC;
		averageFrameTimeMilliseconds  = 1000.0/(fps==0?0.001:fps);
	}
}

double Core::TickRate::getAverageFrameTimeMilliseconds() const
{
	return averageFrameTimeMilliseconds;
}

