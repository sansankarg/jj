#ifndef HARDWARE_ENGINEER_CREATE_DTO_HPP
#define HARDWARE_ENGINEER_CREATE_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"

/// @brief Represents the dto to create hardware engineer
struct HardwareEngineerCreateDto
{
    std::string strPassword;
    std::string strName;
    POSITION ePosition;
    int nSalary;
    int nHardwareUnitCount;
};

#endif