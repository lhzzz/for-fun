#ifndef __SERVICE_IMPL__HH__
#define __SERVICE_IMPL__HH__ 

#include <iostream>
#include <vector>
#include "service.h"
#include "servicedao_file_impl.h"

namespace CM
{
	class Service_impl:public Service
	{
		Servicedao* m_pDao;
		std::vector<Department>* m_vecDepts;
	public:
		Service_impl(void);
		bool addDepart(Department& dept);
        bool deleteDepart(int depid);
        void listDepart(void);
        bool addEmploy(Employee & emp,int depid);
        bool deleteEmploy(int empid,int depid);
        bool modifyEmploy(Employee & emp,int depid);
        void listEmploy(int depid);
        void listAllEmploy(void);
		~Service_impl(void);
	};
}

#endif