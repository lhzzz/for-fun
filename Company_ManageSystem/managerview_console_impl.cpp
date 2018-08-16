#include <iostream>
#include <string>
#include <vector>
#include "tools.h"
#include "managerview_console_impl.h"
#include "managerservice_impl.h"
#include "serviceview_console_impl.h"
#include "emis.h"

using namespace std;
using namespace CM;

Managerview_console_impl::Managerview_console_impl(void)
{
	service = new Managerservice_impl;
	Tools tool;
	tool.initid(MGID_PATH,1001);
}
bool Managerview_console_impl::login(void)
{
	cout << "Please Input Your Manager ID:";
	int id = 0;
	cin >> id;getchar();
	cout << "Please Input Your Password:";
	char password[20];
	cin.get(password,sizeof(password));
	getchar();
	
	return service->sureManager(id,password);
	return false;
}
void Managerview_console_impl::menu(void)
{
	while(1)
	{
		Tools t;
		int choice = 0;  
	  	do
	  	{  
		    system("clear");  
		    cout << "   ╭═════════════════════■□■□══════════╮\n";  
		    cout << "   │          Manager   Menu           │\n";  
		    cout << "   ╰════════════■□■□═══════════════════╯\n";  
		    cout << "   ┌─────────────-┐\n";  
		    cout << "   │ 1. Add Manager  2.Del Manager     │\n";  
		    cout << "   │                                   │\n";  
		    cout << "   │ 3. List Manager 0. Quit           │\n";  
		    cout << "   │                                   │\n";  
		    cout << "   └───────────────────-┘\n";  
		    cout << "   请输入选项(0-3):\n"; 
		    stdin -> _IO_read_ptr = stdin -> _IO_read_end;  
		    choice = t.getch();
		}while(choice < '0'||choice > '3');

		switch(choice-'0')
		{
			case 0:return;
			case 1:add();break;
			case 2:del();break;
			case 3:list();break;
		}
		t.anykey2c();
	}	
}
void Managerview_console_impl::add(void)
{
	system("clear");
	
	int id;
	Tools t;
	char name[20];
	char passwd[20];
	
	cout << "Please input username to add Manager:";
	cin.get(name,sizeof(name)).get();
	cout << "Please input password to add Manager:";
	cin.get(passwd,sizeof(passwd)).get();
	id = t.getid(MGID_PATH);

	Manager new_manager(id,name,passwd);
	cout << "Add Manager " << boolalpha 
		 << service->addManager(new_manager) << endl;
	
}
void Managerview_console_impl::del(void)
{
	system("clear");
	
	int manager_id;
	cout << "Please input manager_id to delete:";
	cin >> manager_id;
	cin.get();
	cout << "delete " << boolalpha
		 << service->deleteManager(manager_id) << endl;
}
void Managerview_console_impl::list(void)
{
	system("clear");

	vector<Manager> v_Manager;
	v_Manager = service->listManager();
}

Managerview_console_impl::~Managerview_console_impl(void)
{
	delete service;
}