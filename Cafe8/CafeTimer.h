
#ifndef _CAFETIMER_H_
#define _CAFETIMER_H_

#include <ctime>

class CafeTimer
{
public:
	CafeTimer(void);
	virtual ~CafeTimer(void);
	
	void start();
	void reset();
	double getEllapsed() const;

private:
	time_t start_;
};

#endif //_CAFETIMER_H_

