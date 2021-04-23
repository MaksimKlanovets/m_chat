#include "cliPrivateUserData.h"

CLIprivataUserData::CLIprivataUserData()
{
}
const std::string CLIprivataUserData::writeTempName()
{
	std::string n{};
	std::cout << "Enter your name" << std::endl;
	std::cin >> n;
	std::cin.ignore(32767, '\n');
	return n;
}

const std::string CLIprivataUserData::writeTempLogin()
{
	std::string l{};
	std::cout << "Enter login" << std::endl;
	std::cin >> l;
	std::cin.ignore(32767, '\n');
	return l;
}

const std::string CLIprivataUserData::writeTempPassword()
{
	std::string p{};
	std::cout << "Enter password" << std::endl;
	std::cin >> p;
	std::cin.ignore(32767, '\n');
	return p;
}

void CLIprivataUserData::help()
{
	std::cout << "1-> Receive messages" << std::endl;
	std::cout << "2-> Send a message to the user" << std::endl;
	std::cout << "3-> Send to all users" << std::endl;
	std::cout << "4-> Clear messages history" << std::endl;
	std::cout << "0-> Log out of account" << std::endl;

}
