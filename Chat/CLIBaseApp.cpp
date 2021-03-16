#include "CLIBaseApp.h"
#include "CLIprivataUserData.h"
#include "CLImessage.h"

CLIBaseApp::CLIBaseApp()
{
	_baseApp = nullptr;
}

void CLIBaseApp::signIn()
{
	_baseApp = BaseApp::instance();

	CLIBaseApp cliBaseApp;
	CLIprivataUserData cliPrivateData;
	CLI* cli = &cliBaseApp;
	
	PrivateUserData privateUserData;
	privateUserData.setLogin(cliPrivateData.writeTempLogin());
	privateUserData.setPassword(cliPrivateData.writeTempPassword());

	UserData* userData = _baseApp->authUser(privateUserData);;

	do
	{
		cli->help();

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
			CLIprivataUserData cliPrivateUserData;
			string tempLogin = cliPrivateUserData.writeTempLogin();

			CLImessage cliMessage;
			string tempMessage = cliMessage.writeTempMessage();;

			_baseApp->sentMessage(tempLogin, tempMessage);
		}
		break;
		case 3:
		{
			CLImessage cliMessage;

			string tempMessage = cliMessage.writeTempMessage();;
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
	CLIprivataUserData cliPrivareData;

	PrivateUserData privateUserData;
	//записываем временно данные по пользователю 
	privateUserData.setName(cliPrivareData.writeTempName());
	privateUserData.setLogin(cliPrivareData.writeTempLogin());
	privateUserData.setPassword(cliPrivareData.writeTempPassword());

	_baseApp->addUser(privateUserData);

	UserData* userData = _baseApp->authUser(privateUserData);;

	CLI* cli = &cliBaseApp;

	while (true)
	{
		cli->help();

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
			CLIprivataUserData cliPrivateUserData;
			string tempLogin = cliPrivateUserData.writeTempLogin();

			CLImessage cliMessage;
			string tempMessage = cliMessage.writeTempMessage();;

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
		{
			CLImessage cliMessage;

			string tempMessage = cliMessage.writeTempMessage();;

			_baseApp->sentMessageToAll(tempMessage);
		}
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




