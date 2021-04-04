#include "baseApp.h"
#include "cli.h"
#include "cliBaseApp.h"
#include <iostream>
#include <ctime>
int main()
{


	setlocale(LC_ALL, "ru");
	//создание базы на основе singelton
	BaseApp *baseApp = BaseApp::instance();

	CLIBaseApp  cliBaseApp;
	CLI *cli = &cliBaseApp;
	cout << "To terminate the program 0 " << endl;
	do
	{
		cout << "Sign in 1" << endl;
		cout << "Sign up 2" << endl;
		
		unsigned int choice = {};
		cin >> choice;
		cin.ignore(32767, '\n');
		if (choice == 0) { break; }
		try
		{
			switch (choice)
			{
			case 1:
			{
				cliBaseApp.signIn();
				break;
			}
			case 2:
			{
				cliBaseApp.signUp();
				break;
			}
			default:
				cout << "wrong input" << endl;
				break;
			}
		}
		catch (const char *ex)
		{
			cout << ex << endl;
		}
	
	} while (true);
	return 0;
}