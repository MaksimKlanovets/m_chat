#include "message.h"

Message::Message(std::string message):_message(message)
{
}

std::string Message::getMessage()
{
	return _message;
}


