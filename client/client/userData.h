#pragma once
#include <string>
#include <iostream>
#include "message.h"
#include <vector>
#include "privateUserData.h"

class UserData
{
public:
	UserData& operator=(const UserData& copy);

	UserData();
	UserData(const UserData& copy);
	UserData( PrivateUserData const &privateUserData);

	const std::string getLogin() const ;
	const std::string getPassword() const;
	const std::string getName() const;
	const Message &getLastMessage();

	void setLogin(const std::string &login);
	void setPassword(const std::string &password);
	void setName(const std::string &name);
	
	const Message* setMessage(UserData *userData,const std::string&);
	void setMessageData( Message&& messageData);
	void printMessage();
	const size_t getSizeArMes() const;
	const void clearHistoryMessages();
private:
	PrivateUserData _privateUserData;
	std::vector<Message> _messages;
	
};

