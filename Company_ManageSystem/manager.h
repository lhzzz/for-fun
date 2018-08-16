#ifndef __MANAGER__HH__
#define __MANAGER__HH__ 

#include <iostream>
#include <string>

namespace CM
{
	class Manager
	{
		int id;
		char name[20];
		char password[20];
		friend std::ostream& operator << (std::ostream&os,const Manager & manager);
		Manager(int _id = 0,const char* _name = "None",const char* _password = "*");
		int getManager_id(void);
		bool sureManager(int id,const char* password);
		~Manager(void);
	};

}
#endif