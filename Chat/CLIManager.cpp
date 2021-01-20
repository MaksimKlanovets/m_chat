#include "CLIManager.h"

CLIManager::CLIManager()
{
	std::cout << "Добро пожаловать в чат" << std::endl;
	this->_signIn = nullptr;
	this->_signUp = nullptr;
	this->_cli = nullptr;
}

void CLIManager::start()
{
	this->_signIn = new SignIn;
	std::cout << "Войти-> 1; Зарегистрироваться-> 2; " << std::endl;
	_signIn->startSignIn();

}
