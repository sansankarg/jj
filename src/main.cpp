#include <iostream>
#include <vector>
#include <iostream>
#include <iomanip>

#include "repositories/IUserRepository.hpp"
#include "repositories/UserRepository.hpp"
#include "seeder/UserSeeder.hpp"
#include "services/ServiceProvider.hpp"
#include "ui/ConsoleUi.hpp"
#include "validators/UserInputValidator.hpp"
#include "controllers/AuthController.hpp"
#include "controllers/UserManager.hpp"
#include "dto/AuthSession.hpp"
 



int main()
{    
    CUserRepository cUserRepository;
    IUserRepository* iUserRepository = &cUserRepository;
    UserSeeder::Seed(iUserRepository);
    CServiceProvider cServiceProvider(iUserRepository);
    ConsoleUI cConsoleUI;
    CUserInputValidator cUserInputValidator;

    CAuthController cAuthController(cConsoleUI, cServiceProvider, cUserInputValidator);
    
    AuthSessionDto stAuthSessionDto = cAuthController.HandleLogin();
    AuthPolicy cAuthPolicy;


    CUserManager cUserManager(cConsoleUI, cServiceProvider, cUserInputValidator, cAuthPolicy);

    cUserManager.HandleMenu(stAuthSessionDto);
}

