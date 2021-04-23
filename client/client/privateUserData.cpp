#include "privateUserData.h"

PrivateUserData::PrivateUserData()
{
	_name = {};
	_pData = {};
}

PrivateUserData::PrivateUserData(const std::string &login,
	const  std::string& password):PrivateUserData()
{
	_pData.first = login;
	_pData.second = password;
}

PrivateUserData::PrivateUserData(
	const std::string &name,
	const std::string &login, 
	const std::string &password)
	:PrivateUserData(login,password
	)
{
	_name = name;
}

PrivateUserData& PrivateUserData::operator=(
	const PrivateUserData&copyObj
	)
{
	if (this == &copyObj)
		return *this;

	_name = copyObj._name;
	_pData = copyObj._pData;

	return *this;
}

const std::string PrivateUserData::getName() const
{
	return _name;
}

const std::string PrivateUserData::getLogin() const
{
	return _pData.first;
}

const std::string PrivateUserData::getPassword() const
{
	return _pData.second;
}

void PrivateUserData::setName(
	const std::string& name
)
{
	_name = name;
}

void PrivateUserData::setLogin(
	const std::string& login
)
{
	_pData.first = login;
}

void PrivateUserData::setPassword(
	const std::string& password
)
{
	_pData.second = password;
}


