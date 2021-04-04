#pragma once
#include <string>
#include <iostream>
#include "message.h"
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

	const string getLogin() const ;
	const string getPassword() const;
	const string getName() const;
	bool setMessage(UserData *userData,const string&);
	void printMessage();
	const size_t getSizeArMes() const;
private:
	PrivateUserData _privateUserData;
	vector<Message> _messages;
	
};

