#include "UserStore.h"

UserStore::UserStore()
{
	this->_userData = {};
	this->_current = nullptr;
}





void UserData::setName(const std::string name)
{
	this->_name = name;
}

void UserData::setLogin(const std::string login)
{
	this->_login = login;
}

void UserData::setPassword(std::string password)
{
	this->_password = password;
}

std::string UserData::getName()
{
	return this->_name;
}

std::string UserData::getLogin()
{
	return this->_login;
}


