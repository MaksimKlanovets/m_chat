#include "message.h"
#include <sstream>

Message::Message()
{
	std::time_t t = std::time(0);   // get time now
	_dt = std::localtime(&t);
	_data = {};
}


Message::Message(const string& login,const string &message)
{
	
	_data.first = login;
	_data.second = message;


	std::time_t t = std::time(0);   // get time now
	 _dt = std::localtime(&t);
	
}

const string Message::getMessage() const
{
	return _data.second;
}

const string Message::getLogin() const
{
	return _data.first;
}

const tm &Message::getTime()const
{
	return *_dt;
}

void Message::setLogin(string& login)
{
	_data.first = login;
}

void Message::setMessage(string& message)
{
	_data.second = message;
}

void Message::setDt(tm &dt)
{
	_dt->tm_wday = dt.tm_wday;
	_dt->tm_mon = dt.tm_mon + 1;
	_dt->tm_year = dt.tm_year;
	_dt->tm_hour = dt.tm_hour;
	_dt->tm_min = dt.tm_min;
	_dt->tm_sec = dt.tm_sec;
}



