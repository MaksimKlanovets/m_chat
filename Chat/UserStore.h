#pragma once
#include "UserData.h"
#include <iostream>
class UserStore
{
public:
	UserStore();
	UserStore &operator=(const UserStore& copy);
	UserStore(std::string name, std::string login, std::string password);

	void printUserData();
	~UserStore();
private:
	UserData _userData;
	
};

