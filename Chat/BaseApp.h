#pragma once
#include "UserStore.h"
#include "TempStoreForMessages.h"
#include <vector>
#include <string>

class BaseApp
{
public:
	static BaseApp* instance();
	

	BaseApp* ptrBase();
	void addUser(std::string name, std::string login, std::string password);
	void runBaseApp();
	void printDataTest();

	~BaseApp() = delete;
private:
	BaseApp();
	BaseApp(const BaseApp&);
	BaseApp& operator=(const BaseApp&);
	

	static BaseApp* _instance;
	std::vector<UserStore> _current;
	std::vector<TempStoreForMessages> _tempStoreForMessages;

};

