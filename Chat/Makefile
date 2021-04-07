test: main.cpp  libCLI libPrivateUserData libMessage  libUserData libbaseApp 
	g++ -o chat main.cpp -L. libCLI.a libUserData.a  libPrivateUserData.a libMessage.a libbaseApp.a 

libCLI: cli.cpp cli.h cliBaseApp.cpp cliBaseApp.h cliMessage.cpp cliMessage.h cliPrivateUserData.cpp cliPrivateUserData.h
	g++ -o cli.o cli.cpp -c
	g++ -o cliBaseApp.o cliBaseApp.cpp -c
	g++ -o cliMessage.o cliMessage.cpp -c
	g++ -o cliPrivateUserData.o cliPrivateUserData.cpp -c
	ar rc libCLI.a cli.o cliBaseApp.o cliMessage.o cliPrivateUserData.o

libUserData: userData.cpp userData.h
	g++ -o userData.o userData.cpp -c 
	ar rc libUserData.a userData.o

libPrivateUserData: privateUserData.cpp privateUserData.h
	g++ -o privateUserData.o privateUserData.cpp -c 
	ar rc libPrivateUserData.a privateUserData.o 

libMessage: message.cpp message.h
	g++ -o message.o message.cpp -c
	ar rc libMessage.a message.o


libbaseApp: baseApp.cpp baseApp.h 
	g++ -o baseApp.o baseApp.cpp -c
	ar rc libbaseApp.a baseApp.o 
	


