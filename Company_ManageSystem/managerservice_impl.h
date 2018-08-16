#ifndef __MANAGERSERVICE__IMPL__HH__
#define __MANAGERSERVICE__IMPL__HH__ 

#include <iostream>
#include "managerservice.h"
#include "managerdao_file_impl.h"

namespace CM
{
	class Managerservice_impl:public Managerservice
	{
       Managerdao* dao;
       std::vector <Manager> *m;
	public:
		Managerservice_impl(void);
		bool sureManager(int id,const char* password);
		bool addManager(const Manager & manager);
        bool deleteManager(int id);
        std::vector<Manager> listManager(void);
		~Managerservice_impl(void);	
	};
}

#endif