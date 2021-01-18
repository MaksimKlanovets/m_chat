#pragma once
#include <iostream>

class UserData
{
public:

	void setName(const std::string name);
	void setLogin(const std::string login);
	void setPassword(const std::string password);

	std::string getName();
	std::string getLogin();
	//std::string getPassword(std::string password);
private:
	std::string _name;
	std::string _login;
	std::string _password;
};

class UserStore:public UserData
{
public:
	UserStore();
	
private:
	UserData _userData;
	UserData *_current;
};

