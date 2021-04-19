#include "privateUserData.h"

PrivateUserData::PrivateUserData()
{
	_name = {};
	_pData = {};
}

PrivateUserData::PrivateUserData(const string &login,const  string& password):PrivateUserData()
{
	_pData.first = login;
	_pData.second = password;
}

PrivateUserData::PrivateUserData(const string &name, const string &login, const string &password)
	:PrivateUserData(login,password)
{
	_name = name;
}

PrivateUserData& PrivateUserData::operator=(const PrivateUserData&copyObj)
{
	if (this == &copyObj)
		return *this;

	_name = copyObj._name;
	_pData = copyObj._pData;

	return *this;
}

const string PrivateUserData::getName() const
{
	return _name;
}

const string PrivateUserData::getLogin() const
{
	return _pData.first;
}

const string PrivateUserData::getPassword() const
{
	return _pData.second;
}

void PrivateUserData::setName(const string& name)
{
	_name = name;
}

void PrivateUserData::setLogin(const string& login)
{
	_pData.first = login;
}

void PrivateUserData::setPassword(const string& password)
{
	_pData.second = password;
}


