#pragma once
#include <string>
#include <ctime>
using namespace std;
class Message
{
public:
	Message();
	Message(const string& ,const string&);

	const string getMessage() const;
	const string getLogin() const;
	const char* getTime() const;

private:
	pair<string, string> _data;
	char* _dt;
	std::string _message;
};

