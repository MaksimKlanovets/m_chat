#include "CLIManager.h"
#include "BaseApp.h"

CLIManager::CLIManager()
{
	std::cout << "Добро пожаловать в чат" << std::endl;
	
	this->_cli = nullptr;
}

void CLIManager::start()
{
	BaseApp *baseApp = BaseApp::instance();
	
	std::cout << "Войти-> 1; Зарегистрироваться-> 2; " << std::endl;
//проверка
	
	SignUp signUp;
	signUp.start();

	SignUp signUp1;
	signUp1.start();
	
	
}

CLIManager::~CLIManager()
{
}
