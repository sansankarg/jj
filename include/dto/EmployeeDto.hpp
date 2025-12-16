#ifndef EMPLOYEE_DTO_HPP
#define EMPLOYEE_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"

/// @brief Represents the dto of hardware engineer
struct EmployeeDto
{
    EmployeeDto(int id, const std::string& name, ROLE eRole, POSITION pos, int salary)
        : nId(id), strName(name), eRole(eRole), ePosition(pos), nSalary(salary)
    {}
    virtual ~EmployeeDto() = default;

    const int nId;
    const std::string strName;
    const ROLE eRole;
    const POSITION ePosition;
    const int nSalary;
};

#endif