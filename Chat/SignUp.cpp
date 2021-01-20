#include "SignUp.h"



SignUp::SignUp()
{
    this->_baseApp = BaseApp::instance();
   
}



bool SignUp::start()
{
    std::cout << "¬ведите им€" << std::endl;
    std::string tempName = "Maks";

    std::cout << "¬ведите login" << std::endl;
    std::string tempLogin = "Login01";

    std::cout << "¬ведите пароль" << std::endl;
    std::string tempPassword = "passw";

   
    _baseApp->addUser(tempName, tempLogin, tempPassword);

    _baseApp->printDataTest();
    return true;
}


SignUp::~SignUp()
{
}


