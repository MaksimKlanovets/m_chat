#include "UserData.h"



UserData& UserData::operator=(const UserData& copy)
{
	if (this == &copy) { return *this; }
	this->_name = copy._name;
	
	return *this;
}



UserData::UserData()
{
	_name = {};
	_login = {};
	_password = {};
}

UserData::UserData(std::string name, std::string login, std::string password)
{
	_name = name;
	_login = login;
	_password = password;
}

std::string UserData::getLogin()
{
	return _login;
}

std::string UserData::getPassword()
{
	return _password;
}

std::string UserData::getName()
{
	return _name;
}

bool UserData::setMessage(string message)
{
	_messages.push_back(message);
	return 0;
	
}

void UserData::printMessage()
{
	for (size_t i = 0; i < _messages.size(); i++)
	{
		cout << _messages[i].getMessage() << endl;
	}
	_messages.clear();
}



std::ostream& operator<<(std::ostream& out, const UserData& userData)
{
	std::cout << "name	 " << userData._name << "\npassword	 " << userData._password <<
		"\nlogin	" << userData._login << std::endl;
	return out;
}
