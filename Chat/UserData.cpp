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



UserData::UserData( PrivateUserData const &privateUserData)
{
	_privateUserData = privateUserData;
}

const std::string UserData::getLogin()
{
	return _privateUserData.getLogin();
}

const std::string UserData::getPassword()
{
	return _privateUserData.getPassword();
}

const std::string UserData::getName()
{
	return _privateUserData.getName();
}

 bool UserData::setMessage(const string &message)
{
	 Message mes(_privateUserData.getLogin(), message);

	_messages.push_back(mes);
	return 0;
	
}

void UserData::printMessage()
{
	for (size_t i = 0; i < _messages.size(); i++)
	{
		cout <<  "User "<< _messages[i].getLogin() << " " <<_messages[i].getTime() ;
		cout << _messages[i].getMessage() << endl << endl;
	}
	_messages.clear();
}



