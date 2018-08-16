#ifndef __EMPLOYEE__HH__
#define __EMPLOYEE__HH__ 

#include <iostream>
#include <string>

namespace CM
{
	class Employee
	{
		
        friend std::ostream& operator << (std::ostream &os,Employee & emp); 
	public:
		int m_nId;
        char m_Name[20];
        bool m_bGender;
        int m_nAge;
		Employee(int id = 0,const char* name = "None",bool bgender = false,int age = 0);
		Employee(const Employee &that);
		int getEmpid(void);
		void ModifyEmp(Employee & emp);
		~Employee();	
	};
}

#endif