#include "CLIManager.h"
#include "SignUp.h"
CLIManager::CLIManager()
{
	std::cout << "����� ���������� � ��� " << std::endl;
	this->_userStore = {};
}

void CLIManager::start()
{
	std::cout << "������� �������" << std::endl;
	 SignUp signUp;
	 std::string name;
	 std::cout << "������� ���" << std::endl;
	 std::cin >> name;
	 signUp.addName(checkName(name));

	 std::string login;
	 std::cout << "������� �����" << std::endl;
	 std::cin >> login;
	 signUp.addLogin(login);

	 std::string password;
	 std::cout << "������� ������" << std::endl;
	 std::cin >> password;
	 signUp.addPassword(password);

}

std::string CLIManager::checkName(std::string name)
{
	for (auto i = 0; i < (this->_userStore.size()); i++)
	{
		if (this->_userStore[i]->getName() != name)
		{
			continue;
		}
		throw("������������ ��� ����� ������ ���������������");
	}
	return name;
}

std::string CLIManager::checkLogin(std::string login)
{
	for (auto i = 0; i < this->_userStore.size(); i++)
	{
		if (this->_userStore[i]->getLogin() != login)
		{
			continue;
		}
		throw("������������ ��� ����� ������� ��� ���������������");
	}
	return login;
}
