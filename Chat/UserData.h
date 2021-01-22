#pragma once
#include <string>
#include <iostream>
#include"message.h"
#include <vector>
using namespace std;
class UserData
{
public:
	UserData& operator=(const UserData& copy);

	UserData();

	UserData(std::string name, std::string login, std::string password);
	string getLogin();
	string getPassword();
	string getName();
	bool setMessage(string);
	void printMessage();

	friend std::ostream& operator<<(std::ostream& out, const UserData& userData);
private:
	string _name;
	string _password;
	string _login;

	vector<Message> _messages;
	
};

