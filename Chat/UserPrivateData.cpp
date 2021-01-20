#include "UserPrivateData.h"





UserPrivateData& UserPrivateData::operator=(const UserPrivateData& copy)
{
	_login = copy._login;
	_password = copy._password;
	return *this;
}

UserPrivateData::UserPrivateData()
{
	this->_login = {};
	this->_password = {};
}


UserPrivateData::UserPrivateData(std::string login, std::string password)
	:_login(login),_password(password)
{
}

//bool UserPrivateData::isUserAuth(std::string login)
//{
//	return (_login != login) ? false : true;
//}


