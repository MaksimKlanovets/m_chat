#include "CLImessage.h"

void CLImessage::help()
{
	cout << "1-> получить смс" << endl;
	cout << "2-> отправить пользователю" << endl;
	cout << "3-> отправить всем пользовател€м" << endl;
	cout << "0-> выйти из учетной записи" << endl;
}

const string CLImessage::writeTempMessage()
{

	string t{};
	cout << "¬ведите сообщение-> " << endl;
	getline(cin, t);
	return t;
}
