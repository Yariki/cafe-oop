#include<iostream>
#include "Cafe.h"

using std::count;
using std::cin;


int main()
{
	try
	{
		Cafe* cafe = new Cafe();
		printf_s("RGR of student %s group %s\n\n","Symon Nastya", "");
		int menu;
		do{
			printf_s("\tSelect action:\n");
			printf_s("1 => Accessors\n");
			printf_s("0 => Exit\n");
			printf_s("Enter command:\n");
			std::cin >> menu;
			switch(menu)
			{
			case 1:
				cafe->simulation();
				break;
			}
		}while(menu  != 0);
		delete cafe;
	}
	catch (std::exception* ex)
	{
		printf_s("Error: %s\n",ex->what());
		delete ex;
	}
	system("pause");
}