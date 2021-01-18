#pragma once
#include "UserStore.h"
#include "TempStoreForMessages.h"

class BaseApp
{
	UserStore *_userStore;
	TempStoreForMessages *_tempStoreForMessages;
};

