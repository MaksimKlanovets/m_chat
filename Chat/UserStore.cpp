#include "UserStore.h"

//UserStore::UserStore()
//{
//}

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
