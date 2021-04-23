#include "cliMessage.h"

void CLImessage::help()
{
}

const std::string CLImessage::writeTempMessage()
{
	std::string t{};
	std::cout << "Enter your message-> " << std::endl;
	std::getline(std::cin, t);
	return t;
}
