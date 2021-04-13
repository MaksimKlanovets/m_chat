#include "baseApp.h"
#include <iostream>

BaseApp* BaseApp::_instance = 0;
BaseApp* BaseApp::instance()
{
	if (_instance == 0)
	{
		_instance = new BaseApp;
	}
	return _instance;
}

void BaseApp::addUser(UserData userData)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != userData.getLogin())
		{
			continue;
		}
		throw "User registered";
	}
	UserData tempUserData = userData;
	_userData.push_back(tempUserData) ;

}

 UserData* BaseApp::authUser( UserData userData)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != userData.getLogin() &&
			_userData[i].getPassword() != userData.getPassword())
		{
			continue;
		}
		_current = &_userData[i];
		
		return &_userData[i];
	}
	throw "Login or password error";
}

const Message *BaseApp::sentMessage(const string &login,const string &message)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != login)
		{
			continue;
		}
		
		_userData[i].setMessage(_current, message);
		//set sender message
		const Message *mes = _current->setMessage(_current, message);
		//save sender message
		writeMessageToFile(login,*mes);
		//get last message
		return &_userData[i].getLastMessage();
	
	}
	return nullptr;
}

bool BaseApp::isLoginAuth(const string &login)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		if (_userData[i].getLogin() != login)
		{
			continue;
		}
		return true;
	}
	return false;
}

const UserData* BaseApp::getCurrent()
{
	return _current;
}

void BaseApp::writeRegUserToFile(const PrivateUserData & privateUserData)
{
	ofstream usersP_file("usersPData.txt", ios::app);

	

	if (!usersP_file.is_open())
	{
		cout << "Could not open the file! " << '\n';
		return;
	}
	//set access rights 
	fs::permissions("usersPData.txt", fs::perms::others_all |
		fs::perms::group_all, fs::perm_options::remove);

	usersP_file << privateUserData.getLogin() << ' ' <<
		privateUserData.getPassword() << ' ' <<
		privateUserData.getName() << '\n';
	usersP_file.close();
}

void BaseApp::writeMessageToFile(const string &login, const Message& message)
{
	
	ofstream userMes_file(login + ".txt", ios::app);
	if (!userMes_file.is_open())
	{
		cout << "error saving message" << endl;
	}
	//set access rights 
	fs::permissions(login + ".txt", fs::perms::others_all |
		fs::perms::group_all, fs::perm_options::remove);

	// day/month/year/hour/min/sec 
	userMes_file  << message.getLogin() << '\n' << 
		message.getTime().tm_mday <<' '	<<
		message.getTime().tm_mon+1 <<' '<<
		message.getTime().tm_year+1900 << 
		' ' << message.getTime().tm_hour << 
		' ' << message.getTime().tm_min<<
		' ' << message.getTime().tm_sec << '\n';

	userMes_file << message.getMessage() << '\n';

	userMes_file.close();
}

void BaseApp::readUsersFromFile()
{
	BaseApp* baseApp = BaseApp::instance();

	ifstream file_reader("usersPData.txt");

	/*if (!file_reader.is_open())
	{
		cout << "Couldn't open the file!" << '\n';
		return;
	}*/
	if (file_reader.is_open())
	{
		string tempData = {};

		string name = {};
		string login = {};
		string passw = {};

		char a = {};
		int point = 0;
		while (file_reader >> login >> passw >> name)
		{
			getline(file_reader, tempData);
			UserData userData;
			userData.setName(name);
			userData.setLogin(login);
			userData.setPassword(passw);
			baseApp->addUser(userData);
		}
	}

	file_reader.close();
}

void BaseApp::readHistoryMes()
{
	BaseApp* baseApp = BaseApp::instance();

	for (size_t i = 0; i < _userData.size(); i++)
	{
		string log = _userData[i].getLogin();
		ifstream file_reader(log+".txt");

		if (!file_reader.is_open())
		{
			continue;
		}
		char a = {};
		string tempData = {};
		int point = 0;
		while (getline(file_reader, tempData))
		{
			Message m;
			tm dt = {};
			//set login
			m.setLogin(tempData);
			tempData.clear();
				
			// day/month/year/hour/min/sec 
			file_reader >> dt.tm_wday >> dt.tm_mon >> dt.tm_year >>
				dt.tm_hour >> dt.tm_min >> dt.tm_sec ;
			//set data-time
		   m.setDt(dt);
		   //read third row, message
		   getline(file_reader, tempData);
		   getline(file_reader, tempData);
		   file_reader >> a;
		   m.setMessage(tempData);

		   //moving object
		   _userData[i].setMessageData(move(m));
		   
		}
		file_reader.close();
	}
}

void BaseApp::sentMessageToAll(const string &message)
{
	for (size_t i = 0; i < _userData.size(); i++)
	{
		_userData[i].setMessage(_current,message);
	}
}

BaseApp::BaseApp()
{
}

BaseApp& BaseApp::operator=(const BaseApp&)
{
	return *this;
}


