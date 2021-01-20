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

BaseApp::BaseApp()
{
	
	this->_current = {};
	this->_tempStoreForMessages = {};
	
}

BaseApp& BaseApp::operator=(const BaseApp&)
{
	return *this;
}

void BaseApp::addUser(std::string name, std::string login, std::string password)
{
	UserStore userStore(name, login, password);
	this->_current.push_back(userStore);
}

BaseApp* BaseApp::ptrBase()
{
	
	return this;
}



void BaseApp::runBaseApp()
{
	std::string choise = "";
		
}

void BaseApp::printDataTest()
{
	for (auto i = 0; i < _current.size(); i++)
	{
		_current[i].printUserData();
	}
}




