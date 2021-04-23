#include "cliBaseApp.h"
#include "cliPrivateUserData.h"
#include "cliMessage.h"

SOCKET Connection;

void ClientHandler() {
	char msg[256];
	while (true) {
		recv(Connection, msg, sizeof(msg), NULL);
		std::cout << msg << std::endl;
	}
}

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
		std::cin >> choice;
		std::cin.ignore(32767, '\n');
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
			std::string tempLogin = cliPrivateUserData.writeTempLogin();

			CLImessage cliMessage;
			std::string tempMessage = cliMessage.writeTempMessage();;
			//sent and write to receiver
			 const Message *sentM = _baseApp->sentMessage(tempLogin, tempMessage);

			if (sentM)
			{
				std::cout << "Message delivered" << std::endl;
				//write messages to file sender
				_baseApp->writeMessageToFile(_baseApp->getCurrent()->getLogin(),*sentM);
			}
			else
			{
				std::cout << "Message not delivered" << std::endl;
			}
		}
		break;
		case 3:
		{
			CLImessage cliMessage;

			std::string tempMessage = cliMessage.writeTempMessage();;
			std::getline(std::cin, tempMessage);

			_baseApp->sentMessageToAll(tempMessage);
		}
		break;
		default:
			std::cout << "Invalid input" << std::endl;
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
	
	
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		throw "Error: failed connect to server.\n";
	}
	std::cout << "Connected!\n";

	//receive wellcome to from server
	char msg[256] = {};
	recv(Connection, msg, sizeof(msg), NULL);
	std::cout << msg << std::endl;
	// send login
	privateUserData.setLogin(cliPrivareData.writeTempLogin());
	std::string log = privateUserData.getLogin();
	int size_log = log.size();
	send(Connection, (char*)&size_log, sizeof(int), NULL);
	send(Connection, log.c_str(), size_log, NULL);
	//send name
	privateUserData.setName(cliPrivareData.writeTempName());
	std::string name = privateUserData.getName();
	int size_name = name.size();
	send(Connection, (char*)&size_name, sizeof(int), NULL);
	send(Connection, name.c_str(), size_name, NULL);
	//send password
	privateUserData.setPassword(cliPrivareData.writeTempPassword());
	std::string pas = privateUserData.getPassword();
	int size_pas = pas.size();
	send(Connection, (char*)&size_pas, sizeof(int), NULL);
	send(Connection, pas.c_str(), size_pas, NULL);

	_baseApp->addUser(privateUserData);
	//write new user to file
	_baseApp->writeRegUserToFile(privateUserData);

	this->signIn();

}

void CLIBaseApp::help()
{
	std::cout << "To terminate the program 0 " << std::endl;
	std::cout << "Sign in 1" << std::endl;
	std::cout << "Sign up 2" << std::endl;
}




