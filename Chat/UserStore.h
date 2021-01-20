#pragma once
#include "UserData.h"

class UserStore
{
public:
	UserStore();
	UserStore &operator=(const UserStore& copy);
	UserStore(std::string name, std::string login, std::string password);



private:
	UserData _userData;
	
};

