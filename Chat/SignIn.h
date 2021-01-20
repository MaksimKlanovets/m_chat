#pragma once
#include "UserAuth.h"
class SignIn:public UserAuth
{
public:
	SignIn();

	bool start() override;
	~SignIn();
private:
};

