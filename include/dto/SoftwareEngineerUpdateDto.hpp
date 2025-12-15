#ifndef SOFTWARE_ENGINEER_UPDATE_DTO_HPP
#define SOFTWARE_ENGINEER_UPDATE_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"

/// @brief Represents the dto to update software engineer
struct SoftwareEngineerUpdateDto
{
    int nId;
    std::string strPassword;
    std::string strName;
    POSITION ePosition;
    int nSalary;
};

#endif