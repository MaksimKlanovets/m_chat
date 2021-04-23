//if define Windows 
#if defined(_WIN32) || defined(WIN64)
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#pragma warning(disable: 4996)
using namespace std;
#define PLATFORM_NAME "Windows" 
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
//
SOCKET Connections[100];
int Counter = 0;


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
//#include <ctime>

void ClientHandler(int index)
{
	//singelton
	BaseApp* baseApp = BaseApp::instance();
	CLIBaseApp cliBaseApp;


	char senderLogin[50] = {};
	char senderMsg[1024] = {};
	char signInOrUp[5] = {};
	while (true) {
		// get sender login
		if (recv(Connections[index], signInOrUp, sizeof(signInOrUp), NULL))
		{


			//find login will sent true or false
			//send(Connections[index], msg, sizeof(msg), NULL);
			while (true)
			{
				if (recv(Connections[index], senderMsg, sizeof(senderMsg), NULL))
				{
					//to sent received message from user to user
					for (int i = 0; i < Counter; i++) {
						if (i == index)
						{

						}

						//send(Connections[i], msg, sizeof(msg), NULL);
}
				}
			}

		}
	}
}

auto main()->int
{
	BaseApp* baseApp = BaseApp::instance();

	
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	for (int i = 0; i < 100; i++) {
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		if (newConnection == 0) {
			std::cout << "Error #2\n";
		}
		else {
			std::cout << "Client Connected!\n";
			char msg[256] = "Hello. Server is working!";
			send(newConnection, msg, sizeof(msg), NULL);

			int msg_size{0};
			while (true)
			{
				//receive log
				recv(newConnection, (char*)&msg_size, sizeof(int), NULL);
				char* log = new char[msg_size + 1];
				log[msg_size] = '\0';
				recv(newConnection, log, msg_size, NULL);
				if (!baseApp->isLoginAuth(log))
				{
					//receive name
					recv(newConnection, (char*)&msg_size, sizeof(int), NULL);
					char* name = new char[msg_size + 1];
					name[msg_size] = '\0';
					recv(newConnection, name, msg_size, NULL);
					//receive password
					recv(newConnection, (char*)&msg_size, sizeof(int), NULL);
					char* pas = new char[msg_size + 1];
					pas[msg_size] = '\0';
					recv(newConnection, pas, msg_size, NULL);
					//create user
					PrivateUserData privateUserData;
					privateUserData.setLogin(log);
					privateUserData.setName(name);
					privateUserData.setPassword(pas);

					delete[]name;
					delete[]pas;

				}
				

					delete[] log;
				
				
			}
			
			
			Connections[i] = newConnection;
			Counter++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
		}
	}

	return 0;
}