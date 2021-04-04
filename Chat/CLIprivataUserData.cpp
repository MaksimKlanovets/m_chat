#include "cliprivataUserData.h"

CLIprivataUserData::CLIprivataUserData()
{
}
const string CLIprivataUserData::writeTempName()
{
	string n{};
	cout << "¬ведите »м€" << endl;
	cin >> n;
	cin.ignore(32767, '\n');
	return n;
}

const string CLIprivataUserData::writeTempLogin()
{
	string l{};
	cout << "¬ведите логин" << endl;
	cin >> l;
	cin.ignore(32767, '\n');
	return l;
}

const string CLIprivataUserData::writeTempPassword()
{
	string p{};
	cout << "¬ведите пароль" << endl;
	cin >> p;
	cin.ignore(32767, '\n');
	return p;
}

void CLIprivataUserData::help()
{
	
}
