#pragma once
#include "UserData.h"
#include <vector>
#include <string>
#include <unordered_set>
class BaseApp
{
public:
	static BaseApp* instance();
	
	void addUser(UserData userData);
    UserData *authUser( UserData userData);
	void sentMessageToAll(const string &message);
	bool sentMessage(const string &login, const string &message);
	bool isLoginAuth(const string &login);
	
	~BaseApp() = delete;
private:
	BaseApp();
	BaseApp(const BaseApp&);
	BaseApp& operator=(const BaseApp&);
	static BaseApp* _instance;
	std::vector <UserData> _userData;
};

