#ifndef __TOOLS__HH__
#define __TOOLS__HH__ 

namespace CM
{
	class Tools
	{
	public:
		void anykey2c(void);
		int getch(void);
		bool initid(const char* mgid_path,int mgid);
		int getid(const char* mgid_path);
	};

}
#endif