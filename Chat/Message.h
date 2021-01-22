#pragma once
#include <string>
class Message
{
public:
	Message(std::string);

	std::string getMessage();

private:
	std::string _message;
};

