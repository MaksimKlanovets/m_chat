#include "userData.h"

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

const std::string UserData::getLogin()const
{
	return _privateUserData.getLogin();
}

const std::string UserData::getPassword()const
{
	return _privateUserData.getPassword();
}

const std::string UserData::getName() const
{
	return _privateUserData.getName();
}

const Message& UserData::getLastMessage()
{
	return _messages.back();
}



void UserData::setLogin(const std::string& login)
{
	_privateUserData.setLogin(login);
}

void UserData::setPassword(const std::string& password)
{
	_privateUserData.setPassword(password);
}

void UserData::setName(const std::string& name)
{
	_privateUserData.setName(name);
}

 const Message* UserData::setMessage(UserData *userData, const std::string &message)
{
	  Message mes(userData->getLogin(), message);
	_messages.push_back(mes);

	return &_messages.back();
}

 void UserData::setMessageData( Message&& messageData)
 {
	 _messages.push_back(messageData);
	 
 }

void UserData::printMessage()
{
	for (size_t i = 0; i < _messages.size(); i++)
	{
		
		std::cout <<  "User "<< _messages[i].getLogin() << ' ';
		// day/month/year/hour/min/sec 
		std::cout<< _messages[i].getTime().tm_mday << '.' <<
				_messages[i].getTime().tm_mon  << '.' <<
				_messages[i].getTime().tm_year <<
			' ' << _messages[i].getTime().tm_hour <<
			':' << _messages[i].getTime().tm_min <<
			':' << _messages[i].getTime().tm_sec << '\n';

			std::cout << _messages[i].getMessage() << std::endl << std::endl;
	}
	
}

const size_t UserData::getSizeArMes() const
{
	return _messages.size();
}

const void UserData::clearHistoryMessages()
{
	_messages.clear();
	return void();
}



