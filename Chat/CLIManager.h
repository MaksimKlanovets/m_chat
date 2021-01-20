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

private:
	SignIn *_signIn;
	SignUp *_signUp;
	CLI* _cli;
};

