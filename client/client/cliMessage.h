#pragma once
#include "cli.h"
class CLImessage:public CLI
{
public:
	void help()override;
	const  std::string writeTempMessage();
};

