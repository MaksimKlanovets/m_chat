#pragma once
#include <string>

class Message
{
public:
	Message();
	Message(const std::string&);
	std::string getMessage();

private:
	std::string _message;
};

