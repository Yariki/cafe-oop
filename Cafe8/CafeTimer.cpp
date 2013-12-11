#include "CafeTimer.h"


CafeTimer::CafeTimer(void)
{
	start_ = 0;
}


CafeTimer::~CafeTimer(void)
{
}

void CafeTimer::reset()
{
	start_ = 0;
}

double CafeTimer::getEllapsed() const
{
	return std::difftime(std::time(nullptr),start_);
}

void CafeTimer::start()
{
	start_ = std::time(nullptr);
}
