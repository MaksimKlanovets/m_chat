#pragma once
#include <string>
#include <ctime>
using namespace std;
#pragma warning(disable: 4996)
class Message
{
public:
	Message();
	Message(const string& ,const string&);

	const string getMessage() const;
	const string getLogin() const;
	const tm &getTime() const;

	void setLogin(string &login);
	void setMessage(string& message);
	void setDt(tm &dt);


private:
	pair<string, string> _data;
	std::tm*  _dt;
};

