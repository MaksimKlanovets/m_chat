#include "cliBaseApp.h"
#include "cliPrivateUserData.h"
#include "cliMessage.h"

CLIBaseApp::CLIBaseApp()
{
	_baseApp = nullptr;
}

void CLIBaseApp::signIn()
{
	_baseApp = BaseApp::instance();

	CLIBaseApp cliBaseApp;
	CLIprivataUserData cliPrivateUserData;
	CLI* cli = &cliPrivateUserData;
	
	PrivateUserData privateUserData;

	privateUserData.setLogin(cliPrivateUserData.writeTempLogin());
	privateUserData.setPassword(cliPrivateUserData.writeTempPassword());

	UserData* userData = _baseApp->authUser(privateUserData);;

	do
	{
		//need create folder sent and receive for correct print 
		/*if (userData->getSizeArMes())
			cout << "Incoming messages " << userData->getSizeArMes() << endl;
		else
			cout << "No incoming messages " << endl;*/

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
			//sent and write to receiver
			 const Message *sentM = _baseApp->sentMessage(tempLogin, tempMessage);

			if (sentM)
			{
				cout << "Message delivered" << endl;
				//write messages to file sender
				_baseApp->writeMessageToFile(_baseApp->getCurrent()->getLogin(),*sentM);
			}
			else
			{
				cout << "Message not delivered" << endl;
			}
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
			cout << "Invalid input" << endl;
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

	privateUserData.setName(cliPrivareData.writeTempName());
	privateUserData.setLogin(cliPrivareData.writeTempLogin());
	privateUserData.setPassword(cliPrivareData.writeTempPassword());

	_baseApp->addUser(privateUserData);
	//write new user to file
	_baseApp->writeRegUserToFile(privateUserData);

}

void CLIBaseApp::help()
{
	cout << "To terminate the program 0 " << endl;
	cout << "Sign in 1" << endl;
	cout << "Sign up 2" << endl;
}




