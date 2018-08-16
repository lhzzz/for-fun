#ifndef __SERVICEVIEW__CONSOLE__IMPL__HH__
#define __SERVICEVIEW__CONSOLE__IMPL__HH__ 

#include "service_impl.h"
#include "serviceview.h"

namespace CM
{
	class Serviceview_console_impl:public Serviceview
	{
		Service* m_pService;
public:
	Serviceview_console_impl(void);
	void menu(void);
    void addDept(void);
    void deleteDept(void);
    void listDept(void);
    void addEmp(void);
    void deleteEmp(void);
    void modifyEmp(void);
    void listEmp(void);
    void listAllEmp(void);
	~Serviceview_console_impl(void);
	};
}
#endif