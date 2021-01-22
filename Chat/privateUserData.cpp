#include "privateUserData.h"

PrivateUserData::PrivateUserData()
{
	_name = {};
	_login = {};
	_password = {};
}

PrivateUserData::PrivateUserData(string login, string password):PrivateUserData()
{
	_login = login;
	_password = password;
}

PrivateUserData::PrivateUserData(string name, string login, string password):PrivateUserData(login,password)
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

void PrivateUserData::setName(string name)
{
	_name = name;
}

void PrivateUserData::setLogin(string login)
{
	_login = login;
}

void PrivateUserData::setPassword(string password)
{
	_password = password;
}

string PrivateUserData::writeTempName()
{
	string n{};
		cout << "¬ведите »м€" << endl;
		cin >> n;
		return n;
}

string PrivateUserData::writeTempLogin()
{
	string l{};
		cout << "¬ведите логин" << endl;
		cin >> l;
		return l;
}

string PrivateUserData::writeTempPassword()
{
	string p{};
		cout << "¬ведите пароль" << endl;
		cin >> p;
		return p;
}
