#include "CLIManager.h"

CLIManager::CLIManager()
{
	std::cout << "Добро пожаловать в чат" << std::endl;
	this->_signIn = {};
	this->_signUp = {};
	this->_cli = nullptr;
}

void CLIManager::start()
{
	std::cout << "Войти-> 1; Зарегистрироваться-> 2; " << std::endl;
	int choise{};

}
