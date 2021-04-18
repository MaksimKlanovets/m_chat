
#if defined(_WIN32) || defined(WIN64)
#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define PLATFORM_NAME "Windows" // Windows 
#define LONG NTSTATUS  * PNTSTATUS
#define STATUS_SUCCESS (0x00000000)
typedef NTSTATUS(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

RTL_OSVERSIONINFOW GetRealOSVersion() {
	HMODULE hMod = ::GetModuleHandleW(L"ntdll.dll");
	if (hMod) {
		RtlGetVersionPtr fxPtr = (RtlGetVersionPtr)::GetProcAddress(hMod, "RtlGetVersion");
		if (fxPtr != nullptr) {
			RTL_OSVERSIONINFOW rovi = { 0 };
			rovi.dwOSVersionInfoSize = sizeof(rovi);
			if (STATUS_SUCCESS == fxPtr(&rovi)) {
				std::cout << "Windows " << rovi.dwMajorVersion <<
					" built " << rovi.dwBuildNumber << std::endl;
				return rovi;
			}
		}
	}
	RTL_OSVERSIONINFOW rovi = { 0 };
	return rovi;
}
OSVERSIONINFOW ow = GetRealOSVersion();

#elif defined(__linux__)
 // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos и другие
#define PLATFORM_NAME "linux"
#include <sys/utsname.h> // Для uname()
#include <iostream>
using namespace std;
bool printLinux()
{
utsname utsname;
uname(&utsname);
cout << "OS name: " << utsname.sysname << endl;
cout << "Host name: " << utsname.nodename << endl;
cout << "OS release: " << utsname.release << endl;
cout << "OS version: " << utsname.version << endl;
cout << "Architecture: " << utsname.machine << endl <<
endl;
return true;
}
bool lin =printLinux();
#elif
cout << "Your OS don't detected, behavior is not definite" << endl;
#endif

#include "baseApp.h"
#include "cli.h"
#include "cliBaseApp.h"
#include <ctime>


auto main()->int
{

	setlocale(LC_ALL, "ru");
	//singelton
	BaseApp *baseApp = BaseApp::instance();
	//read private data from file
	baseApp->readUsersFromFile();
	//read history from file
	baseApp->readHistoryMes();
	CLIBaseApp  cliBaseApp;
	CLI *cli = &cliBaseApp;
		
	do
	{
		cli->help();
				
		unsigned int choice = {};
		cin >> choice;
		cin.ignore(32767, '\n');
		if (choice == 0) { break; }
		try
		{
			switch (choice)
			{
			case 1:
			{
				cliBaseApp.signIn();
				break;
			}
			case 2:
			{
				cliBaseApp.signUp();
				break;
			}
			default:
				cout << "wrong input" << endl;
				break;
			}
		}
		catch (const char *ex)
		{
			cout << ex << endl;
		}
	
	} while (true);
	return 0;
}