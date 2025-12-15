#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include "repositories/RepositoryProvider.hpp"
#include "dto/EmployeeDto.hpp"
#include "dto/HardwareEngineerDto.hpp"
#include "dto/SoftwareEngineerDto.hpp"
#include "dto/ManagementStaffDto.hpp"
#include "enums/Positon.hpp"
#include "ui/ConsoleUi.hpp"

class CUserManager
{
    public:
    CUserManager(ConsoleUI cConsoleUI, CRepositoryProvider cRepositoryProvider);

    void HandleMenu();

    void HandleViewEmployee();

    private:

    void DisplayAllEmployee();

    void DisplayAllHardwareEngineer();

    void DisplayAllSoftwareEngineeer();

    void DisplayAllManagementStaff();

    CRepositoryProvider m_cRepositories;
    
    ConsoleUI m_cConsoleUI;

};

#endif