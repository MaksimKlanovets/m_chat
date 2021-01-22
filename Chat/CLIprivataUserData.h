#pragma once
#include "CLI.h"

class CLIprivataUserData:public CLI
{
public:
	CLIprivataUserData();

	void help()override;
	const string writeTempName();
	const string writeTempLogin();
	const string writeTempPassword();
private:
	
};

