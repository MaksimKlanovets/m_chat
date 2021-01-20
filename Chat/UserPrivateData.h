#pragma once
#include <string>

class UserPrivateData
{
public:
	UserPrivateData& operator=(const UserPrivateData& copy);
	UserPrivateData();
	UserPrivateData(std::string login, std::string password);
	//bool isUserAuth(std::string login);
private:
	std::string _login;
	std::string _password;
};

