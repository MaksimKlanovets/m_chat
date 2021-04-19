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
	const Message &getLastMessage();

	void setLogin(const string &login);
	void setPassword(const string &password);
	void setName(const string &name);
	
	const Message* setMessage(UserData *userData,const string&);
	void setMessageData( Message&& messageData);
	void printMessage();
	const size_t getSizeArMes() const;
	const void clearHistoryMessages();
private:
	PrivateUserData _privateUserData;
	vector<Message> _messages;
	
};

