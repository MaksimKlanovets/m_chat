#pragma once
#include <string>
class Message
{
public:
	Message();
	Message(std::string message);
private:
	std::string _message;
};

