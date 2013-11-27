#include<iostream>
#include "Cafe.h"

using std::count;
using std::cin;


int main()
{
	try
	{
		Cafe* cafe = new Cafe();
		printf_s("RGR of student %s group %s","Symon Anastasiya", "");
		int menu;
		do{
			printf_s("\tSelect action:\n");
			printf_s("1 => Add client\n");
			printf_s("2 => Generate client\n");
			printf_s("3 => Run simulation\n");
			printf_s("0 => Exit\n");
			printf_s("Enter command:\n");
			std::cin >> menu;
			switch(menu)
			{
			case 1:
				cafe->addClient();
				break;
			case 2:
				cafe->generateClients();
				break;
			case 3: 
				cafe->simulation();
				break;
			}
		}while(menu  != 0);
	}
	catch (std::exception* ex)
	{
		printf_s("Error: %s",ex->what());
		delete ex;
	}
	system("pause");
}