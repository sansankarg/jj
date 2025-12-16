#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include "services/ServiceProvider.hpp"
#include "dto/EmployeeDto.hpp"
#include "dto/HardwareEngineerDto.hpp"
#include "dto/SoftwareEngineerDto.hpp"
#include "dto/ManagementStaffDto.hpp"
#include "enums/Positon.hpp"
#include "ui/ConsoleUi.hpp"
#include "validators/UserInputValidator.hpp"
#include "policies/AuthPolicy.hpp"

 
class CUserManager
{
    public:
    CUserManager(ConsoleUI cConsoleUI, CServiceProvider cServiceProvider, CUserInputValidator CUserInputValidator, AuthPolicy cAuthPolicy);

    void HandleMenu(AuthSessionDto stAuthSessionDto);

    void HandleViewEmployee(AuthSessionDto stAuthSessionDto);

    void HandleAddEmployee(AuthSessionDto stAuthSessionDto);

    void HandleRemoveEmployee(AuthSessionDto stAuthSessionDto);

    void HandleUpdatePositionOfEmployee(AuthSessionDto stAuthSessionDto);

    void HandleUpdateSalaryOfEmployee(AuthSessionDto stAuthSessionDto);

    void HandleSearchEmployee(AuthSessionDto stAuthSessionDto);

    private:

    void HandleViewEmployeeByCategory();

    void DislayAllEmployeesWithRole(ROLE eRole);

    void DisplayAllEmployee();

    void DisplayAllHardwareEngineer();

    void DisplayAllSoftwareEngineeer();

    void DisplayAllManagementStaff();

    void HandleViewEmployeeByPosition();

    void DisplayTotalNumberOfEmployees();

    void HandleAddHardwareEngineer();

    void HandleAddSoftwareEngineer();

    void HandleAddManagementStaff();

    std::string GetNameFromUser(std::string strPrompt);

    POSITION GetEmployeePositionFromUser(std::string strPrompt);

    int GetEmployeeSalaryFromUser(std::string strPrompt);

    int GetHardwareUnitsFromUser(std::string strPrompt);

    CServiceProvider m_cServiceProvider;
    
    ConsoleUI m_cConsoleUI;

    CUserInputValidator m_cUserInputValidator;

    AuthPolicy m_cAuthPolicy;

};

#endif