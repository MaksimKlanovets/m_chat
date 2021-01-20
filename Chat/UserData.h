#pragma once
#include "UserPrivateData.h"
#include "Message.h"

class UserData
{
public:
	UserData& operator=(const UserData& copy);
	UserData() ;
	UserData(std::string name, std::string login, std::string password);
	std::string getName();

	~UserData();
private:
	std::string _name;
	 int _id;
	UserPrivateData _userPrivateData;
};

