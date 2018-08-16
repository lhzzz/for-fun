#ifndef __SERVICE__HH__
#define __SERVICE__HH__ 

#include "employee.h"
#include "department.h"
namespace CM
{
	class Service
	{
	public:
	virtual bool addDepart(Department &dept) = 0;
        virtual bool deleteDepart(int depid) = 0;
        virtual void listDepart(void) = 0;
        virtual bool addEmploy(Employee& emp,int depid) = 0;
        virtual bool deleteEmploy(int empid,int depid) = 0;
        virtual bool modifyEmploy(Employee &emp,int depid) = 0;
        virtual void listEmploy(int depid) = 0;
        virtual void listAllEmploy(void) = 0;
        virtual ~Service(void) { }
	};
}

#endif