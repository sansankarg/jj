#include "seeder/UserSeeder.hpp"

#include "entity/User.hpp"
#include "entity/HardwareEngineerData.hpp"
#include "repositories/IUserRepository.hpp"

void UserSeeder::Seed(IUserRepository* iUserRepository)
{
    // Seeds hardware engineers
    {
        CUser hw1(
            0,
            "Abcd@123",
            "Hardware Engineer One",
            ROLE::HARDWARE_ENGINEER,
            POSITION::SENIOR,
            80000
        );
        hw1.SetRoleProfile<HardwareEngineerProfile>(10);
        iUserRepository->Add(std::move(hw1));
    }

    {
        CUser hw2(
            0,
            "Abcd@123",
            "Hardware Engineer Two",
            ROLE::HARDWARE_ENGINEER,
            POSITION::JUNIOR,
            60000
        );
        hw2.SetRoleProfile<HardwareEngineerProfile>(5);
        iUserRepository->Add(std::move(hw2));
    }

    {
        CUser hw3(
            0,
            "Abcd@123",
            "Hardware Engineer Three",
            ROLE::HARDWARE_ENGINEER,
            POSITION::JUNIOR,
            65000
        );
        hw3.SetRoleProfile<HardwareEngineerProfile>(7);
        iUserRepository->Add(std::move(hw3));
    }
    
    // Seeds softwares engineers
    iUserRepository->Add(CUser(
        0,
        "Abcd@123",
        "Software Engineer One",
        ROLE::SOFTWARE_ENGINEER,
        POSITION::SENIOR,
        85000
    ));

    iUserRepository->Add(CUser(
        0,
        "Abcd@123",
        "Software Engineer Two",
        ROLE::SOFTWARE_ENGINEER,
        POSITION::JUNIOR,
        65000
    ));

    iUserRepository->Add(CUser(
        0,
        "Abcd@123",
        "Software Engineer Three",
        ROLE::SOFTWARE_ENGINEER,
        POSITION::JUNIOR,
        70000
    ));
    
    // Seeds management staff
    iUserRepository->Add(CUser(
        0,
        "Abcd@123",
        "Manager One",
        ROLE::MANAGEMENT_STAFF,
        POSITION::SENIOR,
        90000
    ));

    iUserRepository->Add(CUser(
        0,
        "Abcd@123",
        "Manager Two",
        ROLE::MANAGEMENT_STAFF,
        POSITION::JUNIOR,
        70000
    ));

    iUserRepository->Add(CUser(
        0,
        "Abcd123@",
        "Manager Three",
        ROLE::MANAGEMENT_STAFF,
        POSITION::JUNIOR,
        75000
    ));
}
