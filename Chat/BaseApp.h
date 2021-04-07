#pragma once
#include "userData.h"
#include <vector>
#include <string>
#include <fstream>

class BaseApp
{
public:
	static BaseApp* instance();
	
	void addUser(UserData userData);
    UserData *authUser( UserData userData);
	void sentMessageToAll(const string &message);

	const Message *sentMessage(const string &login, const string &message);
	bool isLoginAuth(const string &login);
	const UserData* getCurrent();
	void writeRegUserToFile(const PrivateUserData  &privateUserData);
	void writeMessageToFile(const string& login, const Message& message);
	//read private data
	void readUsersFromFile();
	//read histoty messages
	void readHistoryMes();

	~BaseApp() = delete;
private:
	BaseApp();
	BaseApp(const BaseApp&);
	BaseApp& operator=(const BaseApp&);
	static BaseApp* _instance;
	std::vector <UserData> _userData = {};
	UserData *_current = {};
};

