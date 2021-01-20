#pragma once
#include <string>
class Message
{
public:
	Message();
	Message(std::string message);
	~Message();
private:
	std::string _message;
};

