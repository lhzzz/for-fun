#include <iostream>
#include <fstream>
#include "managerdao_file_impl.h"

using namespace std;
using namespace CM;

Managerdao_file_impl::Managerdao_file_impl(void)
{

}
vector<Manager>& Managerdao_file_impl::load(vector <Manager>& v_manager)
{
	ifstream in;
	in.open("managers.dat",ios::binary);

	for(Manager m;in.read((char*)&m,sizeof(Manager));)
	{
		v_manager.push_back(m);
	}

	in.close();
	return v_manager;
}
void Managerdao_file_impl::save(std::vector<Manager> & v_manager)
{
	ofstream out;
	out.open("managers.dat",ios::binary);

	vector <Manager>::iterator p = v_manager.begin();
	for(int i = 0;p != v_manager.end();p++,i++)
	{
		out.write((char*)&(v_manager.at(i)),sizeof(Manager));
	}

	out.close();
}
Managerdao_file_impl::~Managerdao_file_impl(void)
{

}