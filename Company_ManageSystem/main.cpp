#include <iostream>
#include <vector>
#include "tools.h"
#include "managerview_console_impl.h"
#include "serviceview_console_impl.h"
using namespace std;
using namespace CM;


class SuperUser
{
private:
	static SuperUser superuser;
	Managerview_console_impl M;
	Serviceview_console_impl S;
	SuperUser(void){ run(); }
	SuperUser(SuperUser & that) { }
	void operator = (SuperUser & that) { }
	void run(void)
	{
		while(1)
		{

			int choice;
			Tools t;
			do
			{
				system("clear");
				cout << "   ╭═════════════════════■□■□══════════╮\n";  
			    cout << "   │          Manager   Menu           │\n";  
			    cout << "   ╰════════════■□■□═══════════════════╯\n";  
				cout << "      Manager Menu            <1>      " << endl;
				cout << "      Serview Menu            <2>      " << endl;
				cout << "      Quit                    <0>      " << endl;
				stdin -> _IO_read_ptr = stdin -> _IO_read_end;  
			    choice = t.getch();
			}while(choice < '0'||choice > '2');

			switch(choice - '0')
			{
				case 0:return;
				case 1:M.menu();break;
				case 2:if(M.login())S.menu();break;
			}
			t.anykey2c();
		}
	}
public:
	static SuperUser & getsuperuser(void)
	{
		return superuser;
	}
	~SuperUser() { }
};

SuperUser SuperUser::superuser;

int main(int argc, char const *argv[])
{
	SuperUser &s = SuperUser::getsuperuser();
	return 0;
}
	 

	