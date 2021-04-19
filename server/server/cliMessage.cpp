#include "cliMessage.h"

void CLImessage::help()
{
}

const string CLImessage::writeTempMessage()
{
	string t{};
	cout << "Enter your message-> " << endl;
	getline(cin, t);
	return t;
}
