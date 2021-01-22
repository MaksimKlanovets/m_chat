#include "privateUserData.h"

PrivateUserData::PrivateUserData()
{
	_name = {};
	_login = {};
	_password = {};
}

PrivateUserData::PrivateUserData(const string &login,const  string& password):PrivateUserData()
{
	_login = login;
	_password = password;
}

PrivateUserData::PrivateUserData(const string &name, const string &login, const string &password):PrivateUserData(login,password)
{
	_name = name;
}

PrivateUserData& PrivateUserData::operator=(const PrivateUserData&copyObj)
{
	_name = copyObj._name;
	_login = copyObj._login;
	_password = copyObj._password;
	return *this;
}





string PrivateUserData::getName()
{
	return _name;
}

string PrivateUserData::getLogin()
{
	return _login;
}

string PrivateUserData::getPassword()
{
	return _password;
}

void PrivateUserData::setName(const string& name)
{
	_name = name;
}

void PrivateUserData::setLogin(const string& login)
{
	_login = login;
}

void PrivateUserData::setPassword(const string& password)
{
	_password = password;
}


