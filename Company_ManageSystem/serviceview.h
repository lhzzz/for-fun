#ifndef __SERVICEVIEW__HH__
#define __SERVICEVIEW__HH__ 

namespace CM
{
class Serviceview
{
public:
virtual void menu(void)= 0;
virtual void addDept(void)= 0;
virtual void deleteDept(void)= 0;
virtual void listDept(void)= 0;
virtual void addEmp(void)= 0;
virtual void deleteEmp(void)= 0;
virtual void modifyEmp(void)= 0;
virtual void listEmp(void)= 0;
virtual void listAllEmp(void)= 0;
virtual ~Serviceview(void) { }
};
}

#endif