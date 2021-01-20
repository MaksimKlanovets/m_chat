#pragma once
#include "UserStore.h"
#include "TempStoreForMessages.h"
#include <vector>
#include <string>
class BaseApp
{
public:
	BaseApp();

	void start();

private:
	std::vector<UserStore*> _current;
	std::vector<TempStoreForMessages*> _tempStoreForMessages;

};

