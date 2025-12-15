#ifndef HARDWARE_ENGINEER_UPDATE_DTO_HPP
#define HARDWARE_ENGINEER_UPDATE_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"

/// @brief Represents the dto to update hardware engineer
struct HardwareEngineerUpdateDto
{
    int nId;
    std::string strPassword;
    std::string strName;
    POSITION ePosition;
    int nSalary;
    int nHardwareUnitCount;
};

#endif