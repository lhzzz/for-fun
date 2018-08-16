#ifndef __MANAGERDAO__FILE__IMPL__HH__
#define __MANAGERDAO__FILE__IMPL__HH__ 

#include "managerdao.h"

namespace CM
{
	class Managerdao_file_impl:public Managerdao
	{
	public:
		Managerdao_file_impl();
		std::vector<Manager>& load(std::vector <Manager>& v_manager);
		void save(std::vector<Manager> & v_manager);
		~Managerdao_file_impl();
	};
}

#endif