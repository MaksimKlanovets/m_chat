#include "CLImessage.h"

void CLImessage::help()
{
}

const string CLImessage::writeTempMessage()
{
	string t{};
	cout << "������� ���������-> " << endl;
	getline(cin, t);
	return t;
}
