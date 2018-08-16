#ifndef __MANAGERDAO__HH__
#define __MANAGERDAO__HH__ 

#include <vector>
#include "manager.h"

namespace CM
{
	class Managerdao
	{
	public:
		virtual std::vector<Manager>& load(std::vector <Manager>& v_manager) = 0;
		virtual void save(std::vector <Manager>& v_manager) = 0;
	};
}

#endif