#include <iostream>
#include <cstring>
#include "manager.h"

using namespace CM;
using namespace std;

Manager::Manager(int _id,const char* _name,const char* _password)
{
	id = _id;
	strcpy(name,_name);
	strcpy(password,_password);
}

int Manager::getManager_id(void)
{
	return this->id;
}
bool Manager::sureManager(int id,const char* password)
{
	if ((this->id == id) && 0 == strcmp(this->password,password))
	{
		cout << "Login Successful" << endl;
		return true;
	}
	cout << "Login Fail" << endl;
	return false;
}
Manager::~Manager(void)
{
	
}

namespace CM
{
std::ostream& operator << (std::ostream &os,const Manager & manager)
{
	cout << manager.id << " "
	 << manager.name << " "
	 << manager.password << endl;
	return os; 
}
}