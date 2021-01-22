#include "CLI.h"

void CLI::signIn()
{
	_baseApp = BaseApp::instance();

	string login{};
	string password{};

	cout << "Введите логин" << endl;
	cin >> login;

	cout << "Введите пароль" << endl;
	cin >> password;

	UserData* userData = _baseApp->authUser(login, password);;

	
	do
	{
		
		cout << "1-> получить смс" << endl;
		cout << "2-> отправить пользователю" << endl;
		cout << "3-> отправить всем пользователям" << endl;
		cout << "0-> выйти из учетной записи" << endl;

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
			cout << "Введите логин пользователя для отправки смс-> " << endl;
			getline(cin, tempLogin);

			string tempMessage{};
			cout << "Введите логин пользователя для отправки смс-> " << endl;
			getline(cin, tempMessage);

			_baseApp->sentMessage(tempLogin,tempMessage);
		}
			break;
		case 3:
			break;
		default:
			cout << "Некорректный ввод" << endl;
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

	cout << "Введите Имя" << endl;
	cin >> name;

	cout << "Введите логин" << endl;
	cin >> login;

	cout << "Введите пароль" << endl;
	cin >> password;

	_baseApp->addUser(name, login, password);

	UserData* userData = _baseApp->authUser(login, password);;

	
	while (true)
	{
		
		cout << "1-> получить смс" << endl;
		cout << "2-> отправить пользователю" << endl;
		cout << "3-> отправить всем пользователям" << endl;
		cout << "0-> выйти из учетной записи" << endl;
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
			cout << "Введите логин пользователя для отправки смс-> " << endl;
			getline(cin, tempLogin);

			string tempMessage{};
			cout << "Введите смс -> " << endl;
			getline(cin, tempMessage);

			if (!_baseApp->sentMessage(tempLogin, tempMessage)) 
			{
				cout << "Сообщение доставленно" << endl;
			}
			else
			{
				cout << "Сообщение не доставленно" << endl;
			}
		}
		break;
		case 3:
			break;
		default:
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
}
