#include "BaseApp.h"
#include "CLI.h"
#include "CLIBaseApp.h"
#include <iostream>

int main()
{
	
	setlocale(LC_ALL, "ru");
	BaseApp *baseApp = BaseApp::instance();
	CLIBaseApp  cliBaseApp;
	CLI *cli = &cliBaseApp;
	cout << "��� ���������� ������ ��������� 0 " << endl;
	do
	{
		cout << "��� ����� ������� 1" << endl;
		cout << "��� ����������� ������� 2" << endl;
		
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
				cout << "������������ ����" << endl;
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