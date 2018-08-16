#ifndef __SERVICEDAO__HH__
#define __SERVICEDAO__HH__ 

#include <iostream>
#include <string>
#include "employee.h"
#include "department.h"

namespace CM
{
	class Servicedao
	{
	public:
		virtual std::vector<Department> & load_dept(std::vector<Department> & dept) = 0;
		virtual void save_dept(std::vector<Department> & dept) = 0;
		virtual ~Servicedao(void) { }
	};
}
#endif