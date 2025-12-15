#include "seeder/UserSeeder.hpp"

#include "entity/User.hpp"
#include "entity/HardwareEngineerData.hpp"

void UserSeeder::Seed(IUserDbContext* dbContext)
{
    // Seeds hardware engineers
    {
        CUser hw1(
            0,
            "pass123",
            "Hardware Engineer One",
            ROLE::HARDWARE_ENGINEER,
            POSITION::SENIOR,
            80000
        );
        hw1.SetRoleProfile<HardwareEngineerProfile>(10);
        dbContext->Add(std::move(hw1));
    }

    {
        CUser hw2(
            0,
            "pass123",
            "Hardware Engineer Two",
            ROLE::HARDWARE_ENGINEER,
            POSITION::JUNIOR,
            60000
        );
        hw2.SetRoleProfile<HardwareEngineerProfile>(5);
        dbContext->Add(std::move(hw2));
    }

    {
        CUser hw3(
            0,
            "pass123",
            "Hardware Engineer Three",
            ROLE::HARDWARE_ENGINEER,
            POSITION::JUNIOR,
            65000
        );
        hw3.SetRoleProfile<HardwareEngineerProfile>(7);
        dbContext->Add(std::move(hw3));
    }
    
    // Seeds softwares engineers
    dbContext->Add(CUser(
        0,
        "pass123",
        "Software Engineer One",
        ROLE::SOFTWARE_ENGINEER,
        POSITION::SENIOR,
        85000
    ));

    dbContext->Add(CUser(
        0,
        "pass123",
        "Software Engineer Two",
        ROLE::SOFTWARE_ENGINEER,
        POSITION::JUNIOR,
        65000
    ));

    dbContext->Add(CUser(
        0,
        "pass123",
        "Software Engineer Three",
        ROLE::SOFTWARE_ENGINEER,
        POSITION::JUNIOR,
        70000
    ));
    
    // Seeds management staff
    dbContext->Add(CUser(
        0,
        "pass123",
        "Manager One",
        ROLE::MANAGEMENT_STAFF,
        POSITION::SENIOR,
        90000
    ));

    dbContext->Add(CUser(
        0,
        "pass123",
        "Manager Two",
        ROLE::MANAGEMENT_STAFF,
        POSITION::JUNIOR,
        70000
    ));

    dbContext->Add(CUser(
        0,
        "pass123",
        "Manager Three",
        ROLE::MANAGEMENT_STAFF,
        POSITION::JUNIOR,
        75000
    ));
}
