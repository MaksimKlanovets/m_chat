#pragma once
#include "BaseApp.h"
#include "CLI.h"
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

