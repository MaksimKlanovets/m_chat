#pragma once
#include "UserAuth.h"
#include <iostream>
class SignUp:public UserAuth
{
public:
	SignUp();
	bool start() override;

	~SignUp();
private:
	BaseApp *_baseApp;
};

