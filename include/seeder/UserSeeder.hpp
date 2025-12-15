#ifndef USER_SEEDER_HPP
#define USER_SEEDER_HPP

#include "contexts/UserDbContext.hpp"

class UserSeeder
{
public:
    static void Seed(IUserDbContext* dbContext);
};

#endif
