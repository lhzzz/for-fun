#ifndef __DEPARTMENT__HH__
#define __DEPARTMENT__HH__ 

#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

namespace CM
{
   class Department
   {
   	 
      friend std::ostream& operator << (std::ostream &os,Department & depart);
   public:
    char m_strName[20];
    int m_nId;
    std::vector <Employee> m_vecEmps;
   	Department(const char* strName = "None",int id = 0);
    Department(const char* name,int id,std::vector<Employee> vec);
   	int  getDepartid(void);
   	int  getDepartpeople(void);
   	bool addEmp(Employee &emp);
   	bool deleteEmp(int empid);
   	void deleteall(void);
    void listEmp(void);
    bool modifyEmp(Employee emp);
   	~Department();	
   };
}

#endif