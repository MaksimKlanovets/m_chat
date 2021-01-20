#include "UserData.h"



UserData& UserData::operator=(const UserData& copy)
{
	if (this == &copy) { return *this; }
	this->_name = copy._name;
	this->_id = copy._id;
	this->_userPrivateData = copy._userPrivateData;
	return *this;
}



UserData::UserData()
{
	this->_id = {};
	this->_name = {};
	this->_userPrivateData = {};
}

UserData::UserData(std::string name, std::string login, std::string password)
{
	UserPrivateData userPrivateData(login, password);
	this->_name = name;
	_id = 0;
}


