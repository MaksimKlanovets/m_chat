#include "CLIManager.h"
#include "BaseApp.h"

CLIManager::CLIManager()
{
	std::cout << "����� ���������� � ���" << std::endl;
	
	this->_cli = nullptr;
}

void CLIManager::start()
{
	BaseApp *baseApp = BaseApp::instance();
	
	std::cout << "�����-> 1; ������������������-> 2; " << std::endl;
//��������
	
	SignUp signUp;
	signUp.start();

	SignUp signUp1;
	signUp1.start();
	
	
}

CLIManager::~CLIManager()
{
}
