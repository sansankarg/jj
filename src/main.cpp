#include <iostream>
#include <vector>
#include <iostream>
#include <iomanip>

#include "contexts/UserDbContext.hpp"
#include "contexts/IUserDbContext.hpp"
#include "seeder/UserSeeder.hpp"
#include "repositories/RepositoryProvider.hpp"
#include "ui/ConsoleUi.hpp"
#include "controllers/UserManager.hpp"


    

    



int main()
{    
    CUserDbContext dbContext;
    IUserDbContext* ctx = &dbContext;
    UserSeeder::Seed(ctx);
    CRepositoryProvider cRepositoryProvider(ctx);
    ConsoleUI cConsoleUI;
    CUserManager cUserManager(cConsoleUI, cRepositoryProvider);

    cUserManager.HandleMenu();
}

