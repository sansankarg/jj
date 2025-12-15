#ifndef CONSOLE_UI_HPP
#define CONSOLE_UI_HPP

#include<iostream>
#include<limits>
#include<vector>
#include "dto/EmployeeDto.hpp"
#include "dto/HardwareEngineerDto.hpp"
#include "dto/SoftwareEngineerDto.hpp"
#include "dto/ManagementStaffDto.hpp"

constexpr int ID_WIDTH = 5;
constexpr int NAME_WIDTH  = 25;
constexpr int POSITION_WIDTH  = 15;
constexpr int SALARY_WIDTH  = 10;
constexpr int HW_UNITS_WIDTH  = 15;

class ConsoleUI
{
    public:

    ConsoleUI();

    void PromptMessage(std::string strMessage) const;

    int PromptFoValidInteger(std::string strPrompt) const;

    std::string PromptForValidString(std::string strPrompt) const;

    void PrintEmployeeTable(const std::vector<EmployeeDto>& employees) const;

    void PrintHardwareEngineerTable(const std::vector<HardwareEngineerDto>& stHardwareEngineers) const;

    void PrintSoftwareEngineerTable(const std::vector<SoftwareEngineerDto>& stSoftwareEngineerDtos) const;

    void PrintManagementStaffTable(const std::vector<ManagementStaffDto>& stManagementStaffDtos) const;

    private:
    
    void PrintSeparator(int nWidth) const;
};

#endif