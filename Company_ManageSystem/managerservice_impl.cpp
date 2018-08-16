#include <iostream>
#include "managerservice_impl.h"

using namespace CM;
using namespace std;

Managerservice_impl::Managerservice_impl(void)
{
	dao = new Managerdao_file_impl;
    m = new vector<Manager>;
    dao->load(*m);
}
bool Managerservice_impl::sureManager(int id,const char* password)
{
	for (unsigned int i = 0; i < m->size(); ++i)
	{
		if (id == m->at(i).getManager_id())
		{
			return m->at(i).sureManager(id,password);
		}
	}
	cout << "Login Fail" << endl;
	return false;
}
bool Managerservice_impl::addManager(const Manager &manager)
{
	m->push_back(manager);
	return true;
}
bool Managerservice_impl::deleteManager(int id)
{
	vector<Manager>::iterator p = m->begin();
	for (int i = 0;p != m->end(); p++,i++)
	{
		if (id == m->at(i).getManager_id())
		{
			m->erase(p);
			return true;
		}
	}
	return false;
}
std::vector<Manager> Managerservice_impl::listManager(void)
{
	for (unsigned int i = 0; i < m->size(); ++i)
	{
		cout << m->at(i);
	}
	return *m;
}
Managerservice_impl::~Managerservice_impl(void)
{
	dao->save(*m);
	delete dao;
	delete m;
}
