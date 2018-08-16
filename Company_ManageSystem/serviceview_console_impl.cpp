#include <iostream>
#include "tools.h"
#include "emis.h"
#include "serviceview_console_impl.h"

using namespace CM;
using namespace std;

Serviceview_console_impl::Serviceview_console_impl(void)
{
	m_pService = new Service_impl;
	Tools tool;
	tool.initid(DPID_PATH,101);
	tool.initid(EMID_PATH,100001);
}
void Serviceview_console_impl::menu(void)
{
	while(1)
	{
		Tools t;
		int choice = 0;  
	  	do
	  	{  
		    system("clear");  
		    cout << "   ╭═══════════════════════════■□■□══════════╮\n";  
		    cout << "   │           Operation     Menu            │\n";  
		    cout << "   ╰══════════════════■□■□═══════════════════╯\n";  
		    cout << "   ┌─────────────-┐\n";  
		    cout << "   │ 1. Add Department   2.Del Department   │\n";  
		    cout << "   │                                        │\n";  
		    cout << "   │ 3. List Department  4.Add Employee     │\n";  
		    cout << "   │                                        │\n";
		    cout << "   │ 5. Del Employee     6.Modify Employee  │\n";
		    cout << "   │                                        │\n";
		    cout << "   │ 7. List Employee    8.ListAll Employee │\n";
		    cout << "   │                                        │\n";
		    cout << "   │ 0. Quit                                │\n";    
		    cout << "   └───────────────────-┘\n";  
		    cout << "   请输入选项(0-8):\n"; 
		    stdin -> _IO_read_ptr = stdin -> _IO_read_end;  
		    choice = t.getch();
		}while(choice < '0'||choice > '8');

		switch(choice-'0')
		{
			case 0:return;
			case 1:addDept();break;
			case 2:deleteDept();break;
			case 3:listDept();break;
			case 4:addEmp();break;
			case 5:deleteEmp();break;
			case 6:modifyEmp();break;
			case 7:listEmp();break;
			case 8:listAllEmp();break;
		}
		t.anykey2c();
	}
}
void Serviceview_console_impl::addDept(void)
{	
	int id;
	Tools t;
	char departname[20];
	
	cout << "Please input Department Name:";
	cin.get(departname,sizeof(departname)).get();
	id = t.getid(DPID_PATH);
	
	Department newdp(departname,id);
	cout << "Add New Department " << boolalpha
		 << m_pService->addDepart(newdp) << endl;
}
void Serviceview_console_impl::deleteDept(void)
{
	int department_id;
	cout << "Please input the Department ID to delete:";
	cin >> department_id;
	cin.get();

	cout << "delete " << boolalpha
		 << m_pService->deleteDepart(department_id) << endl;
}
void Serviceview_console_impl::listDept(void)
{
	system("clear");
	m_pService->listDepart();
}
void Serviceview_console_impl::addEmp(void)
{
	bool sex;
	Tools t;
	int age,dp_id,emp_id;
	char name[20];

	cout << "Please input Employee Name:";
	cin.get(name,sizeof(name)).get();
	cout << "Please input Employee sex:(m(1)/f(0))";
	cin >> sex;
	cout << "Please input Employee Age:";
	cin >> age;
	cout << "Please input Employee Department ID:";
	cin >> dp_id;
	cin.get();
	emp_id = t.getid(EMID_PATH);

	Employee newemp(emp_id,name,sex,age);
	
	cout << "Add Employee " << boolalpha 
		 << m_pService->addEmploy(newemp,dp_id) << endl;
}
void Serviceview_console_impl::deleteEmp(void)
{
	int emp_id,dp_id;

	cout << "Please input Employee ID:";
	cin >> emp_id;
	cout << "Please input Employee Department ID:";
	cin >> dp_id;
	cin.get();

	cout << "Delete Employee " << boolalpha
	     << m_pService->deleteEmploy(emp_id,dp_id) << endl;
}
void Serviceview_console_impl::modifyEmp(void)
{
	bool sex;
	int age,dp_id,emp_id;
	char name[20];

	cout << "Please input Employee Name:";
	cin.get(name,sizeof(name)).get();
	cout << "Please input Employee sex:(m(1)/f(0))";
	cin >> sex;
	cout << "Please input Employee Age:";
	cin >> age;
	cout << "Please input Employee Department ID:";
	cin >> dp_id;
	cout << "Please input Employee ID:";
	cin >> emp_id;
	cin.get();

	Employee newemp(emp_id,name,sex,age);
	
	cout << "Modify Employee " << boolalpha
	     << m_pService->modifyEmploy(newemp,dp_id) << endl;
}
void Serviceview_console_impl::listEmp(void)
{
	system("clear");
	int dp_id;
	
	cout << "Please input Department ID:";
	cin >> dp_id;
	cin.get();

	m_pService->listEmploy(dp_id);
}
void Serviceview_console_impl::listAllEmp(void)
{
	system("clear");
	m_pService->listAllEmploy();
}
Serviceview_console_impl::~Serviceview_console_impl(void)
{
	delete m_pService;
}