#ifndef HARDWARE_ENGINEER_DTO_HPP
#define HARDWARE_ENGINEER_DTO_HPP

#include<iostream>
#include "enums/Positon.hpp"
#include "enums/Role.hpp"
#include "dto/EmployeeDto.hpp"

/// @brief Represents the dto of hardware engineer
struct HardwareEngineerDto : public EmployeeDto
{
    HardwareEngineerDto(
        int id,
        const std::string& name,
        POSITION pos,
        int salary,
        int hardwareUnitCount
    )
    : EmployeeDto(id, name, ROLE::HARDWARE_ENGINEER, pos, salary),
    nHardwareUnitCount(hardwareUnitCount){}


    const int nHardwareUnitCount;
};

#endif