#include <iostream>
#include <fstream>
#include <vector>
#include "servicedao_file_impl.h"


using namespace CM;
using namespace std;

Servicedao_file_impl::Servicedao_file_impl()
{

}

vector<Department> & Servicedao_file_impl::load_dept(vector<Department> & v_dept)
{
	ifstream in;
	in.open("services.dat",ios::binary);

	for(char name[20];in.read((char*)&name,sizeof(name));)
	{
		
		int id = 0;
		int len = 0;
		vector<Employee> v_emp;
		
		in.read((char*)&id,sizeof(id));
		in.read((char*)&len,sizeof(len));
		for (int i = 0; i < len; ++i)
		{
			Employee emp;
			in.read((char*)&emp,sizeof(emp));
			v_emp.push_back(emp);
		}
		Department dp(name,id,v_emp);
		v_dept.push_back(dp);
	}

	in.close();
	return v_dept;
}

void Servicedao_file_impl::save_dept(vector<Department> & v_dept)
{
	ofstream out;
	out.open("services.dat",ios::binary);

	for (unsigned int i = 0; i < v_dept.size(); ++i)
	{
		unsigned int len = v_dept[i].m_vecEmps.size();

		out.write((char*)&v_dept[i].m_strName,sizeof(v_dept[i].m_strName));
		out.write((char*)&v_dept[i].m_nId,sizeof(v_dept[i].m_nId));
		out.write((char*)&len,sizeof(len));
		for (unsigned int j = 0; j < len; ++j)
		{
			Employee emp (v_dept[i].m_vecEmps[j]);
			out.write((char*)&emp,sizeof(Employee));
		}
	}

	out.close();
}
Servicedao_file_impl::~Servicedao_file_impl()
{

}