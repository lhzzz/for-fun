#include <iostream>
#include <cstring>
#include "department.h"

using namespace std;
using namespace CM;

Department::Department(const char* strName,int id)
{
	strcpy(m_strName,strName);
	m_nId = id;
}
Department::Department(const char* name,int id,std::vector<Employee> vec)
{
	strcpy(m_strName,name);
	m_nId = id;
	m_vecEmps = vec;
}
int  Department::getDepartid(void)
{
	return this->m_nId;
}
int Department::getDepartpeople(void)
{
	return m_vecEmps.size();
}
bool Department::addEmp(Employee &emp)
{
	m_vecEmps.push_back(emp);
	return true;
}
bool Department::deleteEmp(int empid)
{
	vector<Employee>::iterator p = m_vecEmps.begin();
	for (unsigned int i = 0; p != m_vecEmps.end();p++,i++)
	{
		if (empid == m_vecEmps.at(i).getEmpid())
		{
			m_vecEmps.erase(p);
			return true;
		}
	}
	return false;
}
void Department::deleteall(void)
{
/*	vector<Employee>::iterator p = m_vecEmps.begin();
	for (unsigned int i = 0; p != m_vecEmps.end();p++,i++)
	{
		m_vecEmps.erase(p);
	}*/
	m_vecEmps.clear();
}
void Department::listEmp(void)
{
	for (unsigned int i = 0; i < m_vecEmps.size(); ++i)
			cout << m_vecEmps.at(i);
}
bool Department::modifyEmp(Employee emp)
{
	for (unsigned int i = 0; i < m_vecEmps.size(); ++i)
	{
		if (emp.getEmpid() == m_vecEmps.at(i).getEmpid())
		{
			m_vecEmps.at(i).ModifyEmp(emp);
			return true;
		}
	}
	return false;
}
Department::~Department(void)
{
	
}	

namespace CM
{
	ostream& operator << (ostream &os,Department & depart)
	{
		cout << depart.m_nId << " " << depart.m_strName << " "
		<< depart.getDepartpeople() << endl;
		depart.listEmp();
		return os;
	}
}
