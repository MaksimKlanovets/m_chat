#pragma once
#include "CLI.h"
class CLImessage:public CLI
{
public:

	void help()override;
	const  string writeTempMessage();
};

