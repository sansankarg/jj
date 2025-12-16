#ifndef SOFTWARE_ENGINEER_CREATE_DTO_HPP
#define SOFTWARE_ENGINEER_CREATE_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"

/// @brief Represents the dto to create software engineer
struct SoftwareEngineerCreateDto
{
    std::string strPassword;
    std::string strName;
    POSITION ePosition;
    int nSalary;
};

#endif