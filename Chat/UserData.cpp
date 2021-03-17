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

const string UserData::getLogin()const
{
	return _privateUserData.getLogin();
}

const string UserData::getPassword()const
{
	return _privateUserData.getPassword();
}

const string UserData::getName() const
{
	return _privateUserData.getName();
}

 bool UserData::setMessage(UserData *userData, const string &message)
{
	 Message mes(userData->getLogin(), message);
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

const size_t UserData::getSizeArMes() const
{
	return _messages.size();
}



