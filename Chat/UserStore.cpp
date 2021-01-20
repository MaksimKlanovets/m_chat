#include "UserStore.h"

//UserStore::UserStore()
//{
//}

UserStore::UserStore()
{
	_userData = {};
}

UserStore& UserStore::operator=(const UserStore& copy)
{
	this->_userData = copy._userData;
	return *this;
}


UserStore::UserStore(std::string name, std::string login, std::string password)
{
	
	UserData userData(name, login, password);
	this->_userData = userData;
}

void UserStore::printUserData()
{
	std::cout << this->_userData.getName() << std::endl;
}

UserStore::~UserStore()
{
}
