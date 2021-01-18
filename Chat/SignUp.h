#pragma once
#include "UserStore.h"
class SignUp
{
public:
	SignUp();
	void addName(const std::string name);
	void addLogin(const std::string login);
	void addPassword(const std::string password);

private:
	UserData _userData;
};

