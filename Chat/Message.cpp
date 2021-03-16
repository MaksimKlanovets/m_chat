#include "message.h"


Message::Message()
{
	_message = {};
}


Message::Message(const string& login,const string &message)
	:_message(message)
{
	time_t now = time(0);
	dt = ctime(&now);
	_data.first = login;
	_data.second = message;
}

const string Message::getMessage() const
{
	return _message;
}

const string Message::getLogin() const
{
	return _data.first;
}



const char* Message::getTime()const
{
	return dt;
}



