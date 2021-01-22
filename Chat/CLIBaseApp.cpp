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
			cout << "Введите логин пользователя для отправки смс-> " << endl;
			getline(cin, tempLogin);

			string tempMessage{};
			cout << "Введите логин пользователя для отправки смс-> " << endl;
			getline(cin, tempMessage);

			_baseApp->sentMessage(tempLogin, tempMessage);
		}
		break;
		case 3:
		{
			string tempLogin{};
			cout << "Введите логин пользователя для отправки смс-> " << endl;

			getline(cin, tempLogin);

			string tempMessage{};
			cout << "Введите логин пользователя для отправки смс-> " << endl;
			getline(cin, tempMessage);

			_baseApp->sentMessageToAll(tempMessage);
		}
		break;
		default:
			cout << "Некорректный ввод" << endl;
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

	// создать пользователя передать в параметры далее

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

void CLIBaseApp::help()
{
	cout << "1-> получить смс" << endl;
	cout << "2-> отправить пользователю" << endl;
	cout << "3-> отправить всем пользователям" << endl;
	cout << "0-> выйти из учетной записи" << endl;
}




