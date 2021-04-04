#pragma once
#include "baseApp.h"
#include "cli.h"
using namespace std;
class CLIBaseApp:public CLI
{
public:
	CLIBaseApp();

	void signIn();
	void signUp();
	void help()override;
	
private:
	BaseApp* _baseApp;
	UserData _userData;
};

