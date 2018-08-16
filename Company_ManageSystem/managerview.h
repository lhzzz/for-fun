#ifndef __MANAGERVIEW__HH__
#define __MANAGERVIEW__HH__ 

#include "manager.h"

namespace CM
{
class Managerview
{
public:
	virtual void menu(void) = 0;
	virtual void add(void) = 0;
	virtual void del(void) = 0;
	virtual void list(void) = 0;
	virtual ~Managerview(void) { }	
};

}

#endif