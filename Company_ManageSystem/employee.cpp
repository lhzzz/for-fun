#include <iostream>
#include <cstring>
#include "employee.h"

using namespace CM;
using namespace std;

Employee::Employee(int id,const char* name,bool bgender,int age)
{
	m_nId = id;
	strcpy(m_Name,name);
	m_bGender = bgender;
	m_nAge = age;
}

Employee::Employee(const Employee &that)
{
	this->m_nId = that.m_nId;
	strcpy(this->m_Name,that.m_Name);
	this->m_bGender = that.m_bGender;
	this->m_nAge = that.m_nAge;
}

int Employee::getEmpid(void)
{
	return this->m_nId;
}

void Employee::ModifyEmp(Employee & emp)
{
	strcpy(m_Name,emp.m_Name);
	m_bGender = emp.m_bGender;
	m_nAge = emp.m_nAge;
}
Employee::~Employee()
{
	
}	

namespace CM
{
	ostream& operator << (ostream &os,Employee & emp)
	{
		cout << emp.m_nId << " "
			 << emp.m_Name << " "
			 << emp.m_bGender << " "
			 << emp.m_nAge << endl;
		return os;
	}

}