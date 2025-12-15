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

int ConsoleUI::PromptFoValidInteger(std::string strPrompt) const
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
        else
        {
            return nInput;
        }
    }
    
}

std::string ConsoleUI::PromptForValidString(std::string strPrompt) const
{
    while(true)
    {
        std::string strInput;
        std::cout<<strPrompt;
        std::getline(std::cin, strInput);
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Invalid input !"<<std::endl;
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
        ID_WIDTH + NAME_WIDTH + POSITION_WIDTH + SALARY_WIDTH;

    std::cout << std::left
        << std::setw(ID_WIDTH) << "ID"
        << std::setw(NAME_WIDTH) << "Name"
        << std::setw(POSITION_WIDTH) << "Position"
        << std::setw(SALARY_WIDTH) << "Salary"
        << '\n';

    PrintSeparator(nTotalWidth);

    for (const EmployeeDto& stEmployeeDto : stEmployeeDtos)
    {
        std::cout << std::left
            << std::setw(ID_WIDTH) << stEmployeeDto.nId
            << std::setw(NAME_WIDTH) << stEmployeeDto.strName
            << std::setw(POSITION_WIDTH) << to_string(stEmployeeDto.ePosition)
            << std::setw(SALARY_WIDTH) << stEmployeeDto.nSalary
            << '\n';
    }
}


void ConsoleUI::PrintHardwareEngineerTable(const std::vector<HardwareEngineerDto>& stHardwareEngineerDtos) const
{
    const int nTotalWidth =
        ID_WIDTH + NAME_WIDTH + POSITION_WIDTH + SALARY_WIDTH;

    std::cout << std::left
        << std::setw(ID_WIDTH) << "ID"
        << std::setw(NAME_WIDTH) << "Name"
        << std::setw(POSITION_WIDTH) << "Position"
        << std::setw(SALARY_WIDTH) << "Salary"
        << std::setw(SALARY_WIDTH) << "Hardware Units"
        << '\n';

    PrintSeparator(nTotalWidth);

    for (const HardwareEngineerDto& stHardwareEngineerDto : stHardwareEngineerDtos)
    {
        std::cout << std::left
            << std::setw(ID_WIDTH) << stHardwareEngineerDto.nId
            << std::setw(NAME_WIDTH) << stHardwareEngineerDto.strName
            << std::setw(POSITION_WIDTH) << to_string(stHardwareEngineerDto.ePosition)
            << std::setw(SALARY_WIDTH) << stHardwareEngineerDto.nSalary
            << std::setw(SALARY_WIDTH) << stHardwareEngineerDto.nHardwareUnitCount
            << '\n';
    }
} 

void ConsoleUI::PrintSoftwareEngineerTable(const std::vector<SoftwareEngineerDto>& stSoftwareEngineerDtos) const
{
    const int nTotalWidth =
        ID_WIDTH + NAME_WIDTH + POSITION_WIDTH + SALARY_WIDTH;

    std::cout << std::left
        << std::setw(ID_WIDTH) << "ID"
        << std::setw(NAME_WIDTH) << "Name"
        << std::setw(POSITION_WIDTH) << "Position"
        << std::setw(SALARY_WIDTH) << "Salary"
        << '\n';

    PrintSeparator(nTotalWidth);

    for (const SoftwareEngineerDto& stSoftwareEngineerDto : stSoftwareEngineerDtos)
    {
        std::cout << std::left
            << std::setw(ID_WIDTH) << stSoftwareEngineerDto.nId
            << std::setw(NAME_WIDTH) << stSoftwareEngineerDto.strName
            << std::setw(POSITION_WIDTH) << to_string(stSoftwareEngineerDto.ePosition)
            << std::setw(SALARY_WIDTH) << stSoftwareEngineerDto.nSalary
            << '\n';
    }
}

void ConsoleUI::PrintManagementStaffTable(const std::vector<ManagementStaffDto>& stManagementStaffDtos) const
{
    const int nTotalWidth =
        ID_WIDTH + NAME_WIDTH + POSITION_WIDTH + SALARY_WIDTH;

    std::cout << std::left
        << std::setw(ID_WIDTH) << "ID"
        << std::setw(NAME_WIDTH) << "Name"
        << std::setw(POSITION_WIDTH) << "Position"
        << std::setw(SALARY_WIDTH) << "Salary"
        << '\n';

    PrintSeparator(nTotalWidth);

    for (const ManagementStaffDto& stManagementStaffDto : stManagementStaffDtos)
    {
        std::cout << std::left
            << std::setw(ID_WIDTH) << stManagementStaffDto.nId
            << std::setw(NAME_WIDTH) << stManagementStaffDto.strName
            << std::setw(POSITION_WIDTH) << to_string(stManagementStaffDto.ePosition)
            << std::setw(SALARY_WIDTH) << stManagementStaffDto.nSalary
            << '\n';
    }
}


void ConsoleUI::PrintSeparator(int nWidth) const
{
    std::cout << std::string(nWidth, '-') << '\n';
}

