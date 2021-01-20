#include "Message.h"

Message::Message()
{
	this->_message = {};
}

Message::~Message()
{
}

Message::Message(std::string message):
	_message(message)
{
}
