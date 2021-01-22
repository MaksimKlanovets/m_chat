#include "BaseApp.h"
#include <iostream>

BaseApp* BaseApp::_instance = 0;
BaseApp* BaseApp::instance()
{
	if (_instance == 0)
	{
		_instance = new BaseApp;
	}
	return _instance;
}

void BaseApp::addUser(std::string name, std::string login, std::string password)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != login)
		{
			continue;
		}
		throw "пользователь под данным логином уже зарегистрирован";
	}
	UserData userData(name, login, password);
	_userData.push_back(userData) ;
}

UserData* BaseApp::authUser(std::string login, std::string password)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != login &&
			_userData[i].getPassword() != password)
		{
			continue;
		}
		return &_userData[i];
	}
	
	throw "Ошибка логина или пароля";

}


void BaseApp::pringData()
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		std::cout << _userData[i];
	}
}


bool BaseApp::sentMessage(string login,string message)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != login)
		{
			continue;
		}
		if (!_userData[i].setMessage(message)) { return false; }
	}
	return true;
}

BaseApp::BaseApp()
{
	
}

BaseApp& BaseApp::operator=(const BaseApp&)
{
	
	return *this;
}















