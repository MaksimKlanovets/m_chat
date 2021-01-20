#include "BaseApp.h"

BaseApp::BaseApp()
{
	this->_current = {};
	this->_tempStoreForMessages = {};
	
}

void BaseApp::start()
{
	std::string name = { "maks" }, login = { "log" }, password = { "pass" };
	UserStore userStore(name, login, password);
}
