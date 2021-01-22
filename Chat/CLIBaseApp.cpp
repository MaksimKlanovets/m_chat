#include "CLIBaseApp.h"


CLIBaseApp::CLIBaseApp()
{
	_baseApp = nullptr;
}

void CLIBaseApp::signIn()
{
	_baseApp = BaseApp::instance();

	CLIBaseApp cliBaseApp;
	

	PrivateUserData privateUserData;
	privateUserData.setName(privateUserData.writeTempName());
	privateUserData.setLogin(privateUserData.writeTempLogin());
	privateUserData.setPassword(privateUserData.writeTempPassword());



	UserData* userData = _baseApp->authUser(privateUserData);;

	do
	{
		cliBaseApp.help();

		unsigned int choice{};
		cin >> choice;
		cin.ignore(32767, '\n');
		if (choice == 0) { break; }
		switch (choice)
		{
		case 0:
			break;
		case 1:
			userData->printMessage();
			break;
		case 2:
		{
			string tempLogin{};
			cout << "������� ����� ������������ ��� �������� ���-> " << endl;
			getline(cin, tempLogin);

			string tempMessage{};
			cout << "������� ����� ������������ ��� �������� ���-> " << endl;
			getline(cin, tempMessage);

			_baseApp->sentMessage(tempLogin, tempMessage);
		}
		break;
		case 3:
		{
			string tempLogin{};
			cout << "������� ����� ������������ ��� �������� ���-> " << endl;

			getline(cin, tempLogin);

			string tempMessage{};
			cout << "������� ����� ������������ ��� �������� ���-> " << endl;
			getline(cin, tempMessage);

			_baseApp->sentMessageToAll(tempMessage);
		}
		break;
		default:
			cout << "������������ ����" << endl;
			break;
		}
	} while (true);



}

void CLIBaseApp::signUp()
{
	_baseApp = BaseApp::instance();

	CLIBaseApp cliBaseApp;

	PrivateUserData privateUserData;
	privateUserData.setName(privateUserData.writeTempName());
	privateUserData.setLogin(privateUserData.writeTempLogin());
	privateUserData.setPassword(privateUserData.writeTempPassword());

	// ������� ������������ �������� � ��������� �����

	_baseApp->addUser(privateUserData);

	UserData* userData = _baseApp->authUser(privateUserData);;


	while (true)
	{
		
		cliBaseApp.help();


		unsigned int choice{};
		cin >> choice;
		cin.ignore(32767, '\n');
		if (choice == 0) { break; }
		switch (choice)
		{
		case 0:
			break;
		case 1:
			userData->printMessage();
			break;
		case 2:
		{
			string tempLogin{};
			cout << "������� ����� ������������ ��� �������� ���-> " << endl;
			getline(cin, tempLogin);

			string tempMessage{};
			cout << "������� ��� -> " << endl;
			getline(cin, tempMessage);

			if (!_baseApp->sentMessage(tempLogin, tempMessage))
			{
				cout << "��������� �����������" << endl;
			}
			else
			{
				cout << "��������� �� �����������" << endl;
			}
		}
		break;
		case 3:
			break;
		default:
			cout << "������������ ����" << endl;
			break;
		}
	}
}

void CLIBaseApp::help()
{
	cout << "1-> �������� ���" << endl;
	cout << "2-> ��������� ������������" << endl;
	cout << "3-> ��������� ���� �������������" << endl;
	cout << "0-> ����� �� ������� ������" << endl;
}




