#include "CLIManager.h"
#include "SignUp.h"
CLIManager::CLIManager()
{
	std::cout << "Добро пожаловать в чат " << std::endl;
	this->_userStore = {};
}

void CLIManager::start()
{
	std::cout << "Создать аккаунт" << std::endl;
	 SignUp signUp;
	 std::string name;
	 std::cout << "Введите имя" << std::endl;
	 std::cin >> name;
	 signUp.addName(checkName(name));

	 std::string login;
	 std::cout << "Введите логин" << std::endl;
	 std::cin >> login;
	 signUp.addLogin(login);

	 std::string password;
	 std::cout << "Введите пароль" << std::endl;
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
		throw("Пользователь под таким именем зарегистрирован");
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
		throw("Пользователь под таким логином уже зарегистрирован");
	}
	return login;
}
