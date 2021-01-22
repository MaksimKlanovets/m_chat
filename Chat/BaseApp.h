#pragma once
#include "UserData.h"
#include <vector>
#include <string>

class BaseApp
{
public:
	static BaseApp* instance();
	

	void addUser(UserData userData);
	UserData *authUser(UserData userData);
	void pringData();
	void sentMessageToAll(string message);
	bool sentMessage(string login, string message);
	bool isLoginAuth(string login);
	
	~BaseApp() = delete;
private:
	
	BaseApp();
	BaseApp(const BaseApp&);
	BaseApp& operator=(const BaseApp&);
	static BaseApp* _instance;
	
	std::vector <UserData> _userData;
};

