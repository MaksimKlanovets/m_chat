#include "message.h"


Message::Message()
{
	_message = {};
}




Message::Message(const std::string &message):_message(message)
{
}

std::string Message::getMessage()
{
	return _message;
}



