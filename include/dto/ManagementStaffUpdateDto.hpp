#ifndef MANAGEMENT_STAFF_UPDATE_DTO_HPP
#define MANAGEMENT_STAFF_UPDATE_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"

/// @brief Represents the dto to update management staff.
struct ManagementStaffUpdateDto
{
    int nId;
    std::string strPassword;
    std::string strName;
    POSITION ePosition;
    int nSalary;
};

#endif