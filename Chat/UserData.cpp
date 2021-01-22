#include "UserData.h"



UserData& UserData::operator=(const UserData& copy)
{
	if (this == &copy) { return *this; }
	_privateUserData = copy._privateUserData;
	
	return *this;
}



UserData::UserData()
{
	_privateUserData = {};
}

UserData::UserData(const UserData& copy)
{
	_privateUserData = copy._privateUserData;


}



UserData::UserData(PrivateUserData privateUserData)
{
	_privateUserData = privateUserData;
}

std::string UserData::getLogin()
{
	return _privateUserData.getLogin();
}

std::string UserData::getPassword()
{
	return _privateUserData.getPassword();
}

std::string UserData::getName()
{
	return _privateUserData.getName();
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



