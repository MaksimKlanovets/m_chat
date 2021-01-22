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

void BaseApp::addUser(UserData userData)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != userData.getLogin())
		{
			continue;
		}
		throw "������������ ��� ������ ������� ��� ���������������";
	}
	UserData tempUserData = userData;
	_userData.push_back(tempUserData) ;
}

UserData* BaseApp::authUser(UserData userData)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != userData.getLogin() &&
			_userData[i].getPassword() != userData.getPassword())
		{
			continue;
		}
		return &_userData[i];
	}
	
	throw "������ ������ ��� ������";

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

bool BaseApp::isLoginAuth(string login)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != login)
		{
			continue;
		}
		
		return true;
	}
	return false;
}

void BaseApp::sentMessageToAll(string message)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		_userData[i].setMessage(message);
	}
	
}

BaseApp::BaseApp()
{
	
}

BaseApp& BaseApp::operator=(const BaseApp&)
{
	
	return *this;
}















