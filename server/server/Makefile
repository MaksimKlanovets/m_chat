test: main libbaseApp libCLI libPrivateUserData libMessage  libUserData   
	g++ -o chat -L. main.a libbaseApp.a  libCLI.a libUserData.a  libPrivateUserData.a libMessage.a  

main: main.cpp
	g++ -o main.o -std=c++17 main.cpp -c
	ar rc main.a main.o

libbaseApp: baseApp.cpp baseApp.h 
	g++ -o baseApp.o -std=c++17 baseApp.cpp -c
	ar rc libbaseApp.a baseApp.o 

libCLI: cli.cpp cli.h cliBaseApp.cpp cliBaseApp.h cliMessage.cpp cliMessage.h cliPrivateUserData.cpp cliPrivateUserData.h
	g++ -o cli.o -std=c++17 cli.cpp -c
	g++ -o cliBaseApp.o -std=c++17 cliBaseApp.cpp -c
	g++ -o cliMessage.o -std=c++17 cliMessage.cpp -c
	g++ -o cliPrivateUserData.o -std=c++17 cliPrivateUserData.cpp -c
	ar rc libCLI.a cli.o cliBaseApp.o cliMessage.o cliPrivateUserData.o

libUserData: userData.cpp userData.h
	g++ -o userData.o -std=c++17 userData.cpp -c 
	ar rc libUserData.a userData.o

libPrivateUserData: privateUserData.cpp privateUserData.h
	g++ -o privateUserData.o -std=c++17 privateUserData.cpp -c 
	ar rc libPrivateUserData.a privateUserData.o 

libMessage: message.cpp message.h
	g++ -o message.o -std=c++17 message.cpp -c
	ar rc libMessage.a message.o




