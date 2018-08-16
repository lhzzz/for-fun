#include <iostream>
#include "service_impl.h"
#include "servicedao_file_impl.h"
using namespace CM;
using namespace std;

Service_impl::Service_impl(void)
{
	m_pDao = new Servicedao_file_impl;
	m_vecDepts = new vector<Department>;
	m_pDao->load_dept(*m_vecDepts);
}
bool Service_impl::addDepart(Department& dept)
{
	m_vecDepts->push_back(dept);
	return true;
}
bool Service_impl::deleteDepart(int depid)
{
	vector<Department>::iterator p = m_vecDepts->begin();
	for (int i = 0; p != m_vecDepts->end() ;p++,i++)
	{
		if (depid == m_vecDepts->at(i).getDepartid())
		{
			m_vecDepts->at(i).deleteall();
			m_vecDepts->erase(p);
			return true;
		}
	}
	return false;
}
void Service_impl::listDepart(void)
{
	for (unsigned int i = 0; i < m_vecDepts->size(); ++i)
	{
		cout << m_vecDepts->at(i);
	}
}
bool Service_impl::addEmploy(Employee& emp,int depid)
{
	for (unsigned int i = 0; i < m_vecDepts->size(); ++i)
	{
		if (depid == m_vecDepts->at(i).getDepartid())
		{
			return m_vecDepts->at(i).addEmp(emp);
		}
	}
	return false;
}
bool Service_impl::deleteEmploy(int empid,int depid)
{
	for (unsigned int i = 0; i < m_vecDepts->size(); ++i)
	{
		if (depid == m_vecDepts->at(i).getDepartid())
		{
			return m_vecDepts->at(i).deleteEmp(empid);
		}
	}
	return false;
}
bool Service_impl::modifyEmploy(Employee& emp,int depid)
{
	for (unsigned int i = 0; i < m_vecDepts->size(); ++i)
	{
		if (depid == m_vecDepts->at(i).getDepartid())
		{
			return m_vecDepts->at(i).modifyEmp(emp);
		}
	}
	return false;
}
void Service_impl::listEmploy(int depid)
{
	for (unsigned int i = 0; i < m_vecDepts->size(); ++i)
	{
		if (depid == m_vecDepts->at(i).getDepartid())
		{
			m_vecDepts->at(i).listEmp();
		}
	}
}
void Service_impl::listAllEmploy(void)
{
	for (unsigned int i = 0; i < m_vecDepts->size(); ++i)
	{
		m_vecDepts->at(i).listEmp();
	}
}
Service_impl::~Service_impl(void)
{
	m_pDao->save_dept(*m_vecDepts);
	delete m_vecDepts;
	delete m_pDao;
}
