#include "CLIprivataUserData.h"
CLIprivataUserData::CLIprivataUserData()
{
}
const string CLIprivataUserData::writeTempName()
{
	string n{};
	cout << "������� ���" << endl;
	cin >> n;
	cin.ignore(32767, '\n');
	return n;
}

const string CLIprivataUserData::writeTempLogin()
{
	string l{};
	cout << "������� �����" << endl;
	cin >> l;
	cin.ignore(32767, '\n');
	return l;
}

const string CLIprivataUserData::writeTempPassword()
{
	string p{};
	cout << "������� ������" << endl;
	cin >> p;
	cin.ignore(32767, '\n');
	return p;
}

void CLIprivataUserData::help()
{
	cout << "1-> �������� ���" << endl;
	cout << "2-> ��������� ������������" << endl;
	cout << "3-> ��������� ���� �������������" << endl;
	cout << "0-> ����� �� ������� ������" << endl;
}