#include "cliPrivateUserData.h"

CLIprivataUserData::CLIprivataUserData()
{
}
const string CLIprivataUserData::writeTempName()
{
	string n{};
	cout << "Enter your name" << endl;
	cin >> n;
	cin.ignore(32767, '\n');
	return n;
}

const string CLIprivataUserData::writeTempLogin()
{
	string l{};
	cout << "Enter login" << endl;
	cin >> l;
	cin.ignore(32767, '\n');
	return l;
}

const string CLIprivataUserData::writeTempPassword()
{
	string p{};
	cout << "Enter password" << endl;
	cin >> p;
	cin.ignore(32767, '\n');
	return p;
}

void CLIprivataUserData::help()
{
	cout << "1-> Receive messages" << endl;
	cout << "2-> Send a message to the user" << endl;
	cout << "3-> Send to all users" << endl;
	cout << "4-> Clear messages history" << endl;
	cout << "0-> Log out of account" << endl;

}
