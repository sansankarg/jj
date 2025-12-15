#ifndef MANAGEMENT_STAFF_DTO_HPP
#define MANAGEMENT_STAFF_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"
#include "dto/EmployeeDto.hpp"

/// @brief Represents the dto of management staff.
struct ManagementStaffDto : public EmployeeDto
{
    ManagementStaffDto(
        int id,
        const std::string& name,
        POSITION pos,
        int salary
    )
    : EmployeeDto(id, name, ROLE::MANAGEMENT_STAFF, pos, salary){}
};

#endif