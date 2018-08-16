#ifndef __MANAGERVIEW__CONSOLE__IMPL__HH__
#define __MANAGERVIEW__CONSOLE__IMPL__HH__ 

#include "managerview.h"
#include "managerservice.h"

namespace CM
{
	class Managerview_console_impl:public Managerview
	{
       Managerservice* service;
	public:
		Managerview_console_impl(void);
		bool login(void);
		void menu(void);
	    void add(void);
	    void del(void);
	    void list(void);
		~Managerview_console_impl(void);
	};
}
#endif