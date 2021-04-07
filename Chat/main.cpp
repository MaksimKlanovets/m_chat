#include "baseApp.h"
#include "cli.h"
#include "cliBaseApp.h"
#include <iostream>
#include <ctime>
int main()
{


	setlocale(LC_ALL, "ru");
	//singelton
	BaseApp *baseApp = BaseApp::instance();
	//read private data from file
	baseApp->readUsersFromFile();
	//read history from file
	baseApp->readHistoryMes();
	CLIBaseApp  cliBaseApp;
	CLI *cli = &cliBaseApp;
	

	
	do
	{
		cli->help();
		
		
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