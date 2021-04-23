#pragma once
#include <string>
#include <iostream>


class PrivateUserData
{
public:
	PrivateUserData();
	PrivateUserData(const std::string &login, 
		const std::string &password);
	PrivateUserData(const std::string& name,
		const std::string& login,
		const std::string& password);

	PrivateUserData& operator=(const PrivateUserData&);
	const std::string getName()const;
	const std::string getLogin() const;
	const std::string getPassword() const;
	void setName(const std::string &);
	void setLogin(const std::string&);
	void setPassword(const std::string&);

private:
	std::string _name;
	std::pair<std::string, std::string> _pData;
	
	

};

