#pragma once

#include "SignIn.h"
#include "SignUp.h"
#include "CLI.h"

#include <iostream>

class CLIManager
{
public:
	CLIManager();
	void start();

	~CLIManager();
private:
	
	CLI* _cli;
};

