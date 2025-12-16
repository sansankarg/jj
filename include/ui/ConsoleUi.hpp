#ifndef CONSOLE_UI_HPP
#define CONSOLE_UI_HPP

#include<iostream>
#include<limits>
#include<vector>
#include<functional>
#include "dto/EmployeeDto.hpp"
#include "dto/HardwareEngineerDto.hpp"
#include "dto/SoftwareEngineerDto.hpp"
#include "dto/ManagementStaffDto.hpp"

constexpr int g_nID_WIDTH = 5;
constexpr int g_nNAME_WIDTH  = 25;
constexpr int g_nPOSITION_WIDTH  = 15;
constexpr int g_nSALARY_WIDTH  = 10;
constexpr int g_nHW_UNITS_WIDTH  = 15;

class ConsoleUI
{
    public:

    ConsoleUI();

    void PromptMessage(std::string strMessage) const;

    int PromptForValidInteger(std::string strPrompt, std::function<bool(int)> IsValid = nullptr) const;

    std::string PromptForValidString(std::string strPrompt, std::function<bool(std::string)> IsValid = nullptr) const;

    void PrintEmployeeTable(const std::vector<EmployeeDto>& employees) const;

    void PrintHardwareEngineerTable(const std::vector<HardwareEngineerDto>& stHardwareEngineers) const;

    void PrintSoftwareEngineerTable(const std::vector<SoftwareEngineerDto>& stSoftwareEngineerDtos) const;

    void PrintManagementStaffTable(const std::vector<ManagementStaffDto>& stManagementStaffDtos) const;

    private:
    
    void PrintSeparator(int nWidth) const;
};

#endif