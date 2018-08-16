#ifndef __SERVICEDAO_FILE_IMPL__HH__
#define __SERVICEDAO_FILE_IMPL__HH__ 

#include "servicedao.h"
namespace CM
{
	class Servicedao_file_impl:public Servicedao
	{
	public:
		Servicedao_file_impl(void);
		std::vector<Department> & load_dept(std::vector<Department> & v_dept);
		void save_dept(std::vector<Department> & v_dept);
		~Servicedao_file_impl(void);
	};
}

#endif





