#include "CLI.h"

void CLI::signIn()
{
	_baseApp = BaseApp::instance();

	string login{};
	string password{};

	cout << "������� �����" << endl;
	cin >> login;

	cout << "������� ������" << endl;
	cin >> password;

	UserData* userData = _baseApp->authUser(login, password);;

	
	do
	{
		
		cout << "1-> �������� ���" << endl;
		cout << "2-> ��������� ������������" << endl;
		cout << "3-> ��������� ���� �������������" << endl;
		cout << "0-> ����� �� ������� ������" << endl;

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

			_baseApp->sentMessage(tempLogin,tempMessage);
		}
			break;
		case 3:
			break;
		default:
			cout << "������������ ����" << endl;
			break;
		}
	} while (true);
	
	
	
}

void CLI::signUp()
{
	_baseApp = BaseApp::instance();

	string name{};
	string login{};
	string password{};

	cout << "������� ���" << endl;
	cin >> name;

	cout << "������� �����" << endl;
	cin >> login;

	cout << "������� ������" << endl;
	cin >> password;

	_baseApp->addUser(name, login, password);

	UserData* userData = _baseApp->authUser(login, password);;

	
	while (true)
	{
		
		cout << "1-> �������� ���" << endl;
		cout << "2-> ��������� ������������" << endl;
		cout << "3-> ��������� ���� �������������" << endl;
		cout << "0-> ����� �� ������� ������" << endl;
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
