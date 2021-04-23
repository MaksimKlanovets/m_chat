#pragma once
#if defined(_WIN32) || defined(WIN64)
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>

#pragma warning(disable: 4996)
#endif

#include "userData.h"
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

class BaseApp
{
public:
	static BaseApp* instance();
	
	void addUser(UserData userData);
    UserData *authUser( UserData userData);
	void sentMessageToAll(
		const std::string &message
		);

	const Message *sentMessage(
		const std::string &login,
		const std::string &message
		);
	bool isLoginAuth(
		const std::string &login
		);
	const UserData* getCurrent();
	void writeRegUserToFile(
		const PrivateUserData  &privateUserData
		);
	void writeMessageToFile(
		const std::string& login, 
		const Message& message
		);
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

