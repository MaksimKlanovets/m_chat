#pragma once
#include "UserStore.h"
#include <vector>
class CLIManager
{
public:
	CLIManager();
	void start();
	std::string checkName(std::string name);
	std::string checkLogin(std::string login);


private:
	
	std::vector<UserStore*> _userStore;
	
};

