#pragma once
#include <string>
#include <iostream>

using namespace std;

class PrivateUserData
{
public:
	PrivateUserData();
	PrivateUserData(const string &login, const string &password);
	PrivateUserData(const string& name, const string& login, const string& password);

	PrivateUserData& operator=(const PrivateUserData&);
	const string getName()const;
	const string getLogin() const;
	const string getPassword() const;
	void setName(const string &);
	void setLogin(const string&);
	void setPassword(const string&);

private:
	string _name;
	pair<string, string> _pData;
	
	

};

