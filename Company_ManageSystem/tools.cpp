#include <iostream>
#include <fstream>
#include <cstdio>
#include <unistd.h>
#include <termios.h>
#include "tools.h"

using namespace CM;
using namespace std;

void Tools::anykey2c(void)
{
	cout << "Enter anykey to continue..." << endl;
	getch();
}

int Tools::getch(void)
{
	//get terminal profile(backup)
	struct termios old;
	int ret = tcgetattr(STDIN_FILENO, &old);
	if (ret < 0)
	{
		perror("tcgetattr");
		return -1;
	}

	//new terminal profile and cancel echo and ensure
	struct termios _new = old;
	_new.c_lflag &= ~(ICANON|ECHO);

	//set the terminal profile
	ret = tcsetattr(STDIN_FILENO, TCSANOW, &_new);
	if (ret < 0)
	{
		perror("tcgsetattr");
		return -2;
	}

	//get info through new profile
	int key_value = 0;
	do
	{
		key_value += getchar();
	} while (stdin->_IO_read_end - stdin->_IO_read_ptr);

	//reset terminal profile
	ret = tcsetattr(STDIN_FILENO, TCSANOW, &old);
	if (ret < 0)
	{
		perror("tcsetattr");
		return -3;
	}

	//return the key value
	return key_value;
}

bool Tools::initid(const char* mgid_path,int mgid)
{
	ofstream out;
	out.open(mgid_path,ios::out);

	out << mgid;
	out.close();
	return true;
}

int Tools::getid(const char* mgid_path)
{
	int mgid = 0;
	ifstream in;
	ofstream out;
	
	in.open(mgid_path,ios::in);//read
	in >> mgid;
	in.close();

	mgid++;
	out.open(mgid_path,ios::out);//write
	out << mgid;
	out.close();

	return mgid-1;
}