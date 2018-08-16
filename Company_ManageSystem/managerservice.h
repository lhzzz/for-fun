#ifndef __MANAGERSERVICES__HH__
#define __MANAGERSERVICES__HH__ 

#include <vector>
#include <iostream>
#include "manager.h"

namespace CM
{
	class Managerservice
	{
	public:
		virtual bool sureManager(int id,const char* password) = 0;
		virtual bool addManager(const Manager &manager) = 0;
        virtual bool deleteManager(int id) = 0;
        virtual std::vector<Manager> listManager(void) = 0;
        virtual ~Managerservice(void) { }
	};
}
#endif
