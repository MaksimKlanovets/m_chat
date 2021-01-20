#pragma once
#include <string>

class UserPrivateData
{
public:
	UserPrivateData();
	UserPrivateData& operator=(const UserPrivateData& copy);
	
	UserPrivateData(std::string login, std::string password);
	//bool isUserAuth(std::string login);
	~UserPrivateData();
private:
	std::string _login;
	std::string _password;
};

