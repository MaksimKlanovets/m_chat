#include "CLIManager.h"

CLIManager::CLIManager()
{
	std::cout << "����� ���������� � ���" << std::endl;
	this->_signIn = nullptr;
	this->_signUp = nullptr;
	this->_cli = nullptr;
}

void CLIManager::start()
{
	this->_signIn = new SignIn;
	std::cout << "�����-> 1; ������������������-> 2; " << std::endl;
	_signIn->startSignIn();

}
