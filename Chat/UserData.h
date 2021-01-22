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
	UserData(PrivateUserData privateUserData);
	string getLogin();
	string getPassword();
	string getName();
	
	bool setMessage(string);
	void printMessage();

private:
	PrivateUserData _privateUserData;
	vector<Message> _messages;
	
};

