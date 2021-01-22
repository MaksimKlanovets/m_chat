#pragma once
#include <string>
#include <iostream>
#include"message.h"
#include <vector>
#include "privateUserData.h"
using namespace std;
class UserData
{
public:
	UserData& operator=(const UserData& copy);

	UserData();
	UserData(const UserData& copy);
	UserData( PrivateUserData const &privateUserData);
	const string getLogin();
	const string getPassword();
	const string getName();
	
	bool setMessage(const string&);
	void printMessage();

private:
	PrivateUserData _privateUserData;
	vector<Message> _messages;
	
};

