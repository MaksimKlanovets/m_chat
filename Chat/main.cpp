#include "BaseApp.h"
#include "CLI.h"
#include <iostream>

int main()
{
	
	setlocale(LC_ALL, "ru");
	BaseApp *baseApp = BaseApp::instance();
	CLI cli;

	do
	{
		cout << "��� ����� ������� 1" << endl;
		cout << "��� ����������� ������� 2" << endl;
		unsigned int choice = {};
		cin >> choice;
		if (choice == 0) { break; }
		try
		{
			switch (choice)
			{
			case 1:
			{
				cli.signIn();
				break;
			}
			case 2:
			{
				cli.signUp();
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