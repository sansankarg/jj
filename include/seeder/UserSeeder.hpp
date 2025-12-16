#ifndef USER_SEEDER_HPP
#define USER_SEEDER_HPP

#include "repositories/IUserRepository.hpp"

class UserSeeder
{
public:
    static void Seed(IUserRepository* dbContext);
};

#endif
