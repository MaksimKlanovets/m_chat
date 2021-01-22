#pragma once
#include "UserData.h"
#include <vector>
#include <string>

class BaseApp
{
public:
	static BaseApp* instance();
	

	void addUser(std::string name, std::string login, std::string password);
	UserData *authUser(std::string login,std::string password);

	void pringData();
	bool sentMessage(string login, string message);
	~BaseApp() = delete;
private:
	
	BaseApp();
	BaseApp(const BaseApp&);
	BaseApp& operator=(const BaseApp&);
	static BaseApp* _instance;
	
	std::vector <UserData> _userData;
};

