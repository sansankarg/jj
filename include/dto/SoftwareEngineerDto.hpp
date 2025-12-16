#ifndef SOFTWARE_ENGINEER_DTO_HPP
#define SOFTWARE_ENGINEER_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"
#include "dto/EmployeeDto.hpp"

/// @brief Represents the dto of software engineer
struct SoftwareEngineerDto : public EmployeeDto
{
    SoftwareEngineerDto(
        int id,
        const std::string& name,
        POSITION pos,
        int salary
    )
    : EmployeeDto(id, name, ROLE::SOFTWARE_ENGINEER, pos, salary){}
};

#endif