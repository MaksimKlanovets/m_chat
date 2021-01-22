#pragma once
#include <string>
#include <iostream>
using namespace std;

class PrivateUserData
{
public:
	PrivateUserData();
	PrivateUserData(string login, string password);
	PrivateUserData(string name, string login, string password);
	PrivateUserData& operator=(const PrivateUserData&);
	string getName();
	string getLogin();
	string getPassword();
	void setName(string );
	void setLogin(string);
	void setPassword(string);

	string writeTempName();
	string writeTempLogin();
	string writeTempPassword();
private:
	string _name;
	string _login;
	string _password;
	

};

