#include "CLImessage.h"

void CLImessage::help()
{
	cout << "1-> �������� ���" << endl;
	cout << "2-> ��������� ������������" << endl;
	cout << "3-> ��������� ���� �������������" << endl;
	cout << "0-> ����� �� ������� ������" << endl;
}

const string CLImessage::writeTempMessage()
{

	string t{};
	cout << "������� ���������-> " << endl;
	getline(cin, t);
	return t;
}
