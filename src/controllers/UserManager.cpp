#include "controllers/UserManager.hpp"

#include "repositories/RepositoryProvider.hpp"
#include "dto/EmployeeDto.hpp"
#include "dto/HardwareEngineerDto.hpp"
#include "dto/SoftwareEngineerDto.hpp"
#include "dto/ManagementStaffDto.hpp"
#include "enums/Positon.hpp"
#include "ui/ConsoleUi.hpp"

CUserManager::CUserManager(ConsoleUI cConsoleUI, CRepositoryProvider cRepositoryProvider)
        :m_cConsoleUI(cConsoleUI), m_cRepositories(cRepositoryProvider)
        { }

void CUserManager::HandleMenu()
{
    while(true)
    {
        this->m_cConsoleUI.PromptMessage("Home page\n");

        this->m_cConsoleUI.PromptMessage(R"(
        1. View the employee details (By category, Position) and total number of employees
        2. Add a new employee
        3. Remove an existing employee by ID
        4. Update an employee’s position
        5. Update an employee’s salary
        6. Search employee details by ID or by Position
        0. Exit
        )");


        int nUserChoice = this->m_cConsoleUI.PromptFoValidInteger("\nEnter your choice : ");
        
        switch(nUserChoice)
        {
            case 1:
                HandleViewEmployee();
                break;
            case 0:
                return;
        }
    }
}

void CUserManager::HandleViewEmployee()
{
    this->m_cConsoleUI.PromptMessage(R"(
        1. View the employee details by category, Position) and total number of employees
        2. View the employee details by position
        3. View total number of employees
        0. Exit
        )");

    int nUserChoice = this->m_cConsoleUI.PromptFoValidInteger("\nEnter your choice : ");

    switch(nUserChoice)
    {
        case 1:
            DisplayAllEmployee();
            break;
        case 2:
            DisplayAllHardwareEngineer();
            break;
        case 3:
            DisplayAllSoftwareEngineeer();
            break;
        case 0:
            return;
    }
}

void CUserManager::DisplayAllEmployee()
{
    std::vector<EmployeeDto> stEmployees = this->m_cRepositories.m_cEmployee.GetAll();
    this->m_cConsoleUI.PrintEmployeeTable(stEmployees);
    this->m_cConsoleUI.PromptFoValidInteger("\nEnter 0 to exit");
}

void CUserManager::DisplayAllHardwareEngineer()
{
    std::vector<HardwareEngineerDto> stHardwareEngineers = this->m_cRepositories.m_cHardwareEngineers.GetAll();
    this->m_cConsoleUI.PrintHardwareEngineerTable(stHardwareEngineers);
    this->m_cConsoleUI.PromptFoValidInteger("\nEnter 0 to exit");
}

void CUserManager::DisplayAllSoftwareEngineeer()
{
    std::vector<SoftwareEngineerDto> stSoftwareEngineers = this->m_cRepositories.m_cSoftwareEngineers.GetAll();
    this->m_cConsoleUI.PrintSoftwareEngineerTable(stSoftwareEngineers);
    this->m_cConsoleUI.PromptFoValidInteger("\nEnter 0 to exit");
}

void CUserManager::DisplayAllManagementStaff()
{
    std::vector<ManagementStaffDto> stManagementStaff = this->m_cRepositories.m_cManagementStaff.GetAll();
    this->m_cConsoleUI.PrintManagementStaffTable(stManagementStaff);
    this->m_cConsoleUI.PromptFoValidInteger("\nEnter 0 to exit");
}