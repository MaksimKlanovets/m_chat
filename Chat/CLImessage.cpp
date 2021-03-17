#include "CLImessage.h"

void CLImessage::help()
{
}

const string CLImessage::writeTempMessage()
{
	string t{};
	cout << "¬ведите сообщение-> " << endl;
	getline(cin, t);
	return t;
}
