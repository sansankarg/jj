#ifndef MANAGEMENT_STAFF_CREATE_DTO_HPP
#define MANAGEMENT_STAFF_CREATE_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"

/// @brief Represents the dto to create management staff.
struct ManagementStaffCreateDto
{
    std::string strPassword;
    std::string strName;
    POSITION ePosition;
    int nSalary;
};

#endif