#include "SignUp.h"

SignUp::SignUp()
{
	this->_userData = {};
}



void SignUp::addName(const std::string name)
{
	this->_userData.setName(name);
}

void SignUp::addLogin(const std::string login)
{
	this->_userData.setLogin(login);
}

void SignUp::addPassword(const std::string password)
{
	this->_userData.setPassword(password);
}
