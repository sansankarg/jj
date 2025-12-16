#include "ui/ConsoleUi.hpp"

#include<iostream>
#include<limits>
#include<vector>
#include <iostream>
#include <iomanip>
#include<functional>
#include "dto/EmployeeDto.hpp"

ConsoleUI::ConsoleUI() {}

void ConsoleUI::PromptMessage(std::string strMessage) const
{
    std::cout<<strMessage;
    std::cout.flush();
}

int ConsoleUI::PromptForValidInteger(std::string strPrompt, std::function<bool(int)> IsValid) const
{
    while(true)
    {
        int nInput;
        std::cout<<strPrompt;
        std::cin>>nInput;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Invalid or too large number !"<<std::endl;
        }
        else if(IsValid && !IsValid(nInput))
        {
            std::cout << "Invalid input !" << std::endl;
        }
        else
        {
            return nInput;
        }
    }
    
}

std::string ConsoleUI::PromptForValidString(std::string strPrompt, std::function<bool(std::string)> IsValid) const
{
    while(true)
    {
        std::string strInput;
        std::cout<<strPrompt;
        std::getline(std::cin >> std::ws, strInput);
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Invalid input !"<<std::endl;
        }
        else if(IsValid && !IsValid(strInput))
        {
            std::cout << "Invalid input !" << std::endl;
        }
        else
        {
            return strInput;
        }
    }
}

void ConsoleUI::PrintEmployeeTable(const std::vector<EmployeeDto>& stEmployeeDtos) const
{
    const int nTotalWidth =
        g_nID_WIDTH + g_nNAME_WIDTH + g_nPOSITION_WIDTH + g_nSALARY_WIDTH;

    std::cout<<"Employees\n\n";
    std::cout << std::left
        << std::setw(g_nID_WIDTH) << "ID"
        << std::setw(g_nNAME_WIDTH) << "Name"
        << std::setw(g_nPOSITION_WIDTH) << "Position"
        << std::setw(g_nSALARY_WIDTH) << "Salary"
        << '\n';

    PrintSeparator(nTotalWidth);

    for (const EmployeeDto& stEmployeeDto : stEmployeeDtos)
    {
        std::cout << std::left
            << std::setw(g_nID_WIDTH) << stEmployeeDto.nId
            << std::setw(g_nNAME_WIDTH) << stEmployeeDto.strName
            << std::setw(g_nPOSITION_WIDTH) << to_string(stEmployeeDto.ePosition)
            << std::setw(g_nSALARY_WIDTH) << stEmployeeDto.nSalary
            << '\n';
    }
}


void ConsoleUI::PrintHardwareEngineerTable(const std::vector<HardwareEngineerDto>& stHardwareEngineerDtos) const
{
    const int nTotalWidth =
        g_nID_WIDTH + g_nNAME_WIDTH + g_nPOSITION_WIDTH + g_nSALARY_WIDTH + g_nHW_UNITS_WIDTH;

    std::cout<<"Hardware engineers\n\n";
    std::cout << std::left
        << std::setw(g_nID_WIDTH) << "ID"
        << std::setw(g_nNAME_WIDTH) << "Name"
        << std::setw(g_nPOSITION_WIDTH) << "Position"
        << std::setw(g_nSALARY_WIDTH) << "Salary"
        << std::setw(g_nSALARY_WIDTH) << "Hardware Units"
        << '\n';

    PrintSeparator(nTotalWidth);

    for (const HardwareEngineerDto& stHardwareEngineerDto : stHardwareEngineerDtos)
    {
        std::cout << std::left
            << std::setw(g_nID_WIDTH) << stHardwareEngineerDto.nId
            << std::setw(g_nNAME_WIDTH) << stHardwareEngineerDto.strName
            << std::setw(g_nPOSITION_WIDTH) << to_string(stHardwareEngineerDto.ePosition)
            << std::setw(g_nSALARY_WIDTH) << stHardwareEngineerDto.nSalary
            << std::setw(g_nSALARY_WIDTH) << stHardwareEngineerDto.nHardwareUnitCount
            << '\n';
    }
} 

void ConsoleUI::PrintSoftwareEngineerTable(const std::vector<SoftwareEngineerDto>& stSoftwareEngineerDtos) const
{
    const int nTotalWidth =
        g_nID_WIDTH + g_nNAME_WIDTH + g_nPOSITION_WIDTH + g_nSALARY_WIDTH;

    std::cout<<"Software engineers\n\n";
    std::cout << std::left
        << std::setw(g_nID_WIDTH) << "ID"
        << std::setw(g_nNAME_WIDTH) << "Name"
        << std::setw(g_nPOSITION_WIDTH) << "Position"
        << std::setw(g_nSALARY_WIDTH) << "Salary"
        << '\n';

    PrintSeparator(nTotalWidth);

    for (const SoftwareEngineerDto& stSoftwareEngineerDto : stSoftwareEngineerDtos)
    {
        std::cout << std::left
            << std::setw(g_nID_WIDTH) << stSoftwareEngineerDto.nId
            << std::setw(g_nNAME_WIDTH) << stSoftwareEngineerDto.strName
            << std::setw(g_nPOSITION_WIDTH) << to_string(stSoftwareEngineerDto.ePosition)
            << std::setw(g_nSALARY_WIDTH) << stSoftwareEngineerDto.nSalary
            << '\n';
    }
}

void ConsoleUI::PrintManagementStaffTable(const std::vector<ManagementStaffDto>& stManagementStaffDtos) const
{
    const int nTotalWidth =
        g_nID_WIDTH + g_nNAME_WIDTH + g_nPOSITION_WIDTH + g_nSALARY_WIDTH;

    std::cout<<"Management staff\n\n";
    std::cout << std::left
        << std::setw(g_nID_WIDTH) << "ID"
        << std::setw(g_nNAME_WIDTH) << "Name"
        << std::setw(g_nPOSITION_WIDTH) << "Position"
        << std::setw(g_nSALARY_WIDTH) << "Salary"
        << '\n';

    PrintSeparator(nTotalWidth);

    for (const ManagementStaffDto& stManagementStaffDto : stManagementStaffDtos)
    {
        std::cout << std::left
            << std::setw(g_nID_WIDTH) << stManagementStaffDto.nId
            << std::setw(g_nNAME_WIDTH) << stManagementStaffDto.strName
            << std::setw(g_nPOSITION_WIDTH) << to_string(stManagementStaffDto.ePosition)
            << std::setw(g_nSALARY_WIDTH) << stManagementStaffDto.nSalary
            << '\n';
    }
}


void ConsoleUI::PrintSeparator(int nWidth) const
{
    std::cout << std::string(nWidth, '-') << '\n';
}

